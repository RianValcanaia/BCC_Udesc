{- 
   Módulo de Análise Semântica.
   Percorre a AST para:
    1. Verificar compatibilidade de tipos (ex: Int vs Double).
    2. Verificar declaração de variáveis e funções (Escopo).
    3. Inserir nós de coerção de tipos (IntDouble, DoubleInt) na árvore.
   
   ENTRADA (na função tProg):
   - Programa: A AST "bruta" gerada pelo Parser.
   
   SAÍDA:
   - Result Programa: Um monad que encapsula:
     a) Uma flag de erro fatal (Bool).
     b) Logs de erros e avisos (String).
     c) A AST "tipada" (Programa) com as conversões inseridas.
-}

module Semantico where

import Control.Monad (zipWithM)
import RI -- Importa a estrutura da AST

-- ====== Estrutura de Tratamento de erros e avisos ======
-- Result encapsulta: (flagErroFatal, logs, valor)
data Result a = Result (Bool, String, a) deriving Show

instance Functor Result where
  fmap f (Result (b, s, a)) = Result (b, s, f a)

instance Applicative Result where
  pure a = Result (False, "", a)
  Result (b1, s1, f) <*> Result (b2, s2, x) = Result (b1 || b2, s1 ++ s2, f x)    

instance Monad Result where
  Result (b, s, a) >>= f = let Result (b', s', a') = f a
                           in Result (b || b', s ++ s', a')

-- Registra um erro, marca flag de erro fatal
errorMsg :: String -> Result ()
errorMsg s = Result (True, "Erro: " ++ s ++ "\n", ())

-- Registra um aviso, não marca flag de erro fatal
warningMsg :: String -> Result ()
warningMsg s = Result (False, "Advertencia: " ++ s ++ "\n", ())


-- ====== Regras de coerção e tipagem =======
{-
    Regras principais:
    - Operações aritméticas e relacionais aceitam TInt e TDouble. (coercaoExpr e coercaoExprR)
    - Se um operando for TInt e outro TDouble, promove-se o Int para Double. (coercaoExpr e coercaoExprR)
    - Strings só aparecem em operadores relacionais (==, !=, etc.) e os dois
    operandos devem ter o mesmo tipo. (coercaoExprR)
    - Quando há incompatibilidade de tipos, emite-se erro e retorna-se a
    expressão original (coersaoExpr e coercaoExprR).
-}

-- Coerção para Expressões Aritméticas (+, -, *, /)
coercaoExpr :: (Expr -> Expr -> Expr) -> Expr -> Expr -> Tipo -> Tipo -> Result (Tipo, Expr)
coercaoExpr op e1 e2 t1 t2
    | (t1 /= TInt && t1 /= TDouble) = do
        errorMsg ("Erro de tipos na expressao: " ++ show e1 ++ " eh " ++ show t1)
        return (t2, op e1 e2)
    | (t2 /= TInt && t2 /= TDouble) = do
        errorMsg ("Erro de tipos na expressao: " ++ show e2 ++ " eh " ++ show t2)
        return (t1, op e1 e2)
    | t1 == t2 = 
        return (t1, op e1 e2)
    | t1 == TInt && t2 == TDouble = 
        return (t2, op (IntDouble e1) e2) -- Promove e1
    | t1 == TDouble && t2 == TInt = 
        return (t1, op e1 (IntDouble e2)) -- Promove e2
    | otherwise = do
        errorMsg ("Erro de tipos incompatíveis: " ++ show t1 ++ " e " ++ show t2)
        return (t1, op e1 e2)

-- Coerção para Argumentos de Função
coerirArg :: Tipo -> Tipo -> Expr -> Result Expr
coerirArg tipoArg tipoParam arg
    | tipoArg == tipoParam = 
        return arg
    | tipoArg == TInt && tipoParam == 
        TDouble = return (IntDouble arg)
    | tipoArg == TDouble && tipoParam == TInt = do
        warningMsg ("Conversao de Double para Int (perda de precisao): " ++ show arg)
        return (DoubleInt arg)
    | otherwise = do
        errorMsg ("Tipo do argumento " ++ show arg ++ " (" ++ show tipoArg ++ ") nao compativel com parametro (" ++ show tipoParam ++ ")")
        return arg

-- Coere uma lista de triplas (tipoArg, tipoParam, expr) aplicando coerirArg em cada
coerirLista :: [(Tipo, Tipo, Expr)] -> Result [Expr]
coerirLista [] = return []
coerirLista ((tipoArg, tipoParam, arg):xs) = do
    coerido <- coerirArg tipoArg tipoParam arg
    resto <- coerirLista xs
    return (coerido : resto)

-- Coerção para Relacionais (==, <, >, etc)
-- String é permitida apenas aqui
coercaoExprR :: (Expr -> Expr -> ExprR) -> Expr -> Expr -> Tipo -> Tipo -> Result ExprR
coercaoExprR op e1 e2 t1 t2
    | (t1 == TInt && t2 == TInt)       = return (op e1 e2)
    | (t1 == TDouble && t2 == TDouble) = return (op e1 e2)
    | (t1 == TString && t2 == TString) = return (op e1 e2)
    | (t1 == TInt && t2 == TDouble)    = return (op (IntDouble e1) e2)  -- Promove e1
    | (t1 == TDouble && t2 == TInt)    = return (op e1 (IntDouble e2))  -- Promove e2
    | otherwise = do
        errorMsg ("Tipos incompativeis na expressao relacional: " ++ show t1 ++ " e " ++ show t2)
        return (op e1 e2)

-- ======= Análise de Expressões Aritméticas e chamadas =======
{-
    Chamadas de funções com número de parâmetros errados ou com parâmetros
    formais e reais com tipos conflitantes devem ocasionar a emissão de mensagens
    de erro.
    tExpr implementa essas regras em: errorMsg ("Numero incorreto de argumentos para " ++ nome)
    coerirArg implementa essas regras em: errorMsg ("Tipo do argumento " ++ show arg ++ ...

    Chamada de funções não declaradas deve ocasionar a emissão de uma mensagem de erro
    tExpr implementa essa regra em: errorMsg ("Funcao nao declarada: " ++ nome)
-}

-- Tipa expressoes retornando (tipoInferido, exprPorssivelmenteCoercida)
tExpr :: [Funcao] -> [Var] -> Expr -> Result (Tipo, Expr)
tExpr tfun tvar (Const (CInt c))    = return (TInt, Const (CInt c))
tExpr tfun tvar (Const (CDouble c)) = return (TDouble, Const (CDouble c))
tExpr tfun tvar (Lit s)             = return (TString, Lit s)

-- identificador de variável: procura na tabela tvar
tExpr tfun tvar (IdVar nome) = 
    case lookup nome [(i, t) | i :#: (t, _) <- tvar] of
        Just t  -> return (t, IdVar nome)
        Nothing -> do
            errorMsg ("Variavel nao declarada: " ++ show nome)
            return (TVoid, IdVar nome)

-- operador unário somente para tipos numéricos
tExpr tfun tvar (Neg e) = do
    (t, e') <- tExpr tfun tvar e
    if t /= TInt && t /= TDouble 
    then do 
        errorMsg ("Operador unario '-' aplicado a tipo invalido: " ++ show t)
        return (t, Neg e')
    else return (t, Neg e')

-- operacoes binarias aritmeticas: delega para coercaoExpr
tExpr tfun tvar (Add e1 e2) = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExpr Add e1' e2' t1 t2 }
tExpr tfun tvar (Sub e1 e2) = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExpr Sub e1' e2' t1 t2 }
tExpr tfun tvar (Mul e1 e2) = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExpr Mul e1' e2' t1 t2 }
tExpr tfun tvar (Div e1 e2) = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExpr Div e1' e2' t1 t2 }

-- chamada de funcao: tipa os argumentos, verifica assinatura e coercao por parametro
tExpr tfun tvar (Chamada nome args) = do
    argsTipados <- mapM (tExpr tfun tvar) args
    let (tiposArgs, args') = unzip argsTipados
    case lookup nome [(f, (params, ret)) | f :->: (params, ret) <- tfun] of
        Nothing -> do
            errorMsg ("Funcao nao declarada: " ++ nome)
            return (TVoid, Chamada nome args')
        Just (params, tipoRet) ->
            let tiposParams = [t | _ :#: (t, _) <- params]
            in if length tiposArgs /= length tiposParams
                then do
                    errorMsg ("Numero incorreto de argumentos para " ++ nome)
                    return (tipoRet, Chamada nome args')
                else do
                    coeridos <- coerirLista (zip3 tiposArgs tiposParams args')
                    return (tipoRet, Chamada nome coeridos)

-- ======= Análise de Expressões Relacionais =======
-- delega para coercaoExprR
tExprR :: [Funcao] -> [Var] -> ExprR -> Result ExprR
tExprR tfun tvar (Req e1 e2)  = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Req e1' e2' t1 t2 }
tExprR tfun tvar (Rdif e1 e2) = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Rdif e1' e2' t1 t2 }
tExprR tfun tvar (Rlt e1 e2)  = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Rlt e1' e2' t1 t2 }
tExprR tfun tvar (Rgt e1 e2)  = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Rgt e1' e2' t1 t2 }
tExprR tfun tvar (Rle e1 e2)  = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Rle e1' e2' t1 t2 }
tExprR tfun tvar (Rge e1 e2)  = do { (t1, e1') <- tExpr tfun tvar e1; (t2, e2') <- tExpr tfun tvar e2; coercaoExprR Rge e1' e2' t1 t2 }

-- ======= Análise de Expressões Lógicas =======
-- rel: envolve uma expressão relacional; not, and, or apenas reconstroem a AST com subexpressoes tipadas
tExprL :: [Funcao] -> [Var] -> ExprL -> Result ExprL
tExprL tfun tvar (Rel e) = do { e' <- tExprR tfun tvar e; return (Rel e') }
tExprL tfun tvar (Not e) = do { e' <- tExprL tfun tvar e; return (Not e') }
tExprL tfun tvar (And e1 e2) = do { e1' <- tExprL tfun tvar e1; e2' <- tExprL tfun tvar e2; return (And e1' e2') }
tExprL tfun tvar (Or e1 e2)  = do { e1' <- tExprL tfun tvar e1; e2' <- tExprL tfun tvar e2; return (Or e1' e2') }

-- ====== Comandos (Atribuição, If, while) ======
-- aplica tComando a cada comando do bloco
tBloco :: Tipo -> [Funcao] -> [Var] -> Bloco -> Result Bloco
tBloco contexto tfun tvar b = mapM (tComando contexto tfun tvar) b

{-
    Quando uma variável declarada como double receber o valor de uma expressão
    de tipo int, o resultado da expressão deve ser convertido para o tipo double. Isso
    é válido para comandos de atribuição, passagem de parâmetros em chamadas de
    funções e para o retorno de funções.
    Funções tComando e coerirArg implementam essas regras.

    Quando uma variável declarada como int receber o valor de uma expressão de tipo
    double, o resultado da expressão deve ser convertido para o tipo int, nesse caso
    deve ser emitida uma mensagem de advertência. Isso é válido para comandos de
    atribuição, passagem de parâmetros em chamadas de funções e para o retorno de
    funções.
    Função tComando implementa essa regra.

    Atribuição de variáveis ou retorno de funções com tipos conflitantes devem
    ocasionar a emissão de mensagens de erro.
    tComando implementa em: errorMsg ("Atribuicao incompativel: variavel ...
    tComando implementa em: errorMsg ("Retorno invalido. Esperado: ...
-}

-- Responsável por validar e, quando necessario, inserir coerções em comandos
tComando :: Tipo -> [Funcao] -> [Var] -> Comando -> Result Comando
-- atribuicao: verifica a existencia da variavel e coerce o valor atribuido
tComando contexto tfun tvar (Atrib nome e) = do
    (texpr, e') <- tExpr tfun tvar e
    case lookup nome [(i, tv) | i :#: (tv, _) <- tvar] of
        Nothing -> do
            errorMsg ("Variavel nao declarada na atribuicao: " ++ show nome)
            return (Atrib nome e')
        Just tv -> case (tv, texpr) of
            (TInt, TInt)       -> return (Atrib nome e')
            (TDouble, TDouble) -> return (Atrib nome e')
            (TString, TString) -> return (Atrib nome e')
            (TDouble, TInt)    -> return (Atrib nome (IntDouble e')) -- Coerção automática
            (TInt, TDouble)    -> do
                warningMsg ("Atribuicao de Double para variavel Int " ++ show nome ++ " (perda de precisao).")
                return (Atrib nome (DoubleInt e')) -- Coerção com warning
            _ -> do
                errorMsg ("Atribuicao incompativel: variavel " ++ show nome ++ " (" ++ show tv ++ ") recebe " ++ show texpr)
                return (Atrib nome e')


-- retorno: verifica se a funcao deveria retornar algo e coerce o valor retornado
tComando contexto tfun tvar (Ret maybeExpr) = case maybeExpr of
    Nothing -> if contexto == TVoid 
                then return (Ret Nothing) 
                else do { errorMsg "Funcao deve retornar valor"; return (Ret Nothing) }
    Just e -> do
        (texpr, e') <- tExpr tfun tvar e
        case (contexto, texpr) of
            (TInt, TDouble) -> do
                warningMsg "Retorno converte Double para Int."
                return (Ret (Just (DoubleInt e')))
            (TDouble, TInt) -> return (Ret (Just (IntDouble e')))
            (t1, t2) | t1 == t2 -> return (Ret (Just e'))
                | otherwise -> do
                    errorMsg ("Retorno invalido. Esperado: " ++ show contexto ++ ", Encontrado: " ++ show texpr)
                    return (Ret (Just e'))



-- if: valida a condicao e o bloco then/else
tComando contexto tfun tvar (If cond cmdsThen cmdsElse) = do
    cond' <- tExprL tfun tvar cond
    cmdsThen' <- tBloco contexto tfun tvar cmdsThen
    cmdsElse' <- tBloco contexto tfun tvar cmdsElse
    return (If cond' cmdsThen' cmdsElse')

-- while: valida a condicao e o bloco
tComando contexto tfun tvar (While cond comandos) = do
    cond' <- tExprL tfun tvar cond
    comandos' <- tBloco contexto tfun tvar comandos
    return (While cond' comandos')

-- impressao: tipa a expresao e retorna o camando atualizado
tComando contexto tfun tvar (Imp e) = do
    (_, e') <- tExpr tfun tvar e
    return (Imp e')

-- Leitura: verifica se a variavel existe 
tComando contexto tfun tvar (Leitura nome) = do
    case lookup nome [(i, tv) | i :#: (tv, _) <- tvar] of
        Nothing -> do
            errorMsg ("Tentativa de ler variavel nao declarada: " ++ show nome)
            return (Leitura nome)
        Just _ -> return (Leitura nome)

-- chamada de procedimento: tipa argumentos, verifica assinatura e coerce por parametro
tComando contexto tfun tvar (Proc nome args) = do
    argsTipados <- mapM (tExpr tfun tvar) args
    let (tiposArgs, args') = unzip argsTipados
    case lookup nome [(f, (params, ret)) | f :->: (params, ret) <- tfun] of
        Nothing -> do
            errorMsg ("Procedimento nao declarado: " ++ nome)
            return (Proc nome args')
        Just (params, _) -> do
            let tiposParams = [t | _ :#: (t, _) <- params]
            if length tiposArgs /= length tiposParams
            then do
                errorMsg ("Numero incorreto de argumentos para procedimento " ++ nome)
                return (Proc nome args')
            else do
                coeridos <- coerirLista (zip3 tiposArgs tiposParams args')
                return (Proc nome coeridos)

-- ======= Programa Principal e validacoes finais =======
-- Verifica se variáveis estão duplicadas 
{-
    A existência de funções multiplamente declaradas deve
    ocasionar uma mensagem de erro
    tFuncao implementa essa regra.

-}
tFuncao :: [Funcao] -> [Funcao] -> Result [Funcao]
tFuncao acumulador [] = return acumulador
tFuncao acumulador ((nome:->:assinatura):resto) = do
    if nome `elem` [n | (n:->:_) <- acumulador]
    then do
        errorMsg ("Funcao duplicada: " ++ show nome)
        tFuncao acumulador resto
    else
        tFuncao (acumulador ++ [nome:->:assinatura]) resto

-- Verifica duplicatas na lista de variáveis
{-
    A existência de variáveis multiplamente declaradas em uma mesma 
    função deve ocasionar a emissão de uma mensagem de erro.
    tVariavel implementa essa regra.
-}
tVariavel :: [Var] -> [Var] -> Result [Var]
tVariavel acumulador [] = return acumulador
tVariavel acumulador ((nome:#:tp):resto) = do
    if nome `elem` [n | (n:#:_) <- acumulador]
    then do
        errorMsg ("Variavel duplicada: " ++ show nome)
        tVariavel acumulador resto
    else
        tVariavel (acumulador ++ [nome:#:tp]) resto

-- Analisa a definição completa de uma função (declaração + corpo)
tDefinicaoFuncao :: [Funcao] -> (Id, [Var], Bloco) -> Result (Id, [Var], Bloco)
tDefinicaoFuncao tfun (nome, vars, bloco) = do
    -- Verifica se parametros tem nomes duplicados
    vars' <- tVariavel [] vars

    -- Busca o tipo de retorno da função
    let contexto = case lookup nome [(f, (params, ret)) | f :->: (params, ret) <- tfun] of
                    Just (_, ret) -> ret
                    Nothing -> TVoid

    -- Analisa o bloco da função usando as variáveis locais (params)
    bloco' <- tBloco contexto tfun vars' bloco
    return (nome, vars', bloco')

-- Ponto de Entrada: Analisa o Programa Completo
tProg :: Programa -> Result Programa
tProg (Prog declaracoesFuncoes definicoesFuncoes variaveisGlobais blocoPrincipal) = do
    -- 1. Verifica assinaturas duplicadas
    tfun <- tFuncao [] declaracoesFuncoes

    -- 2. Analisa o corpo das funções
    definicoesFuncoes' <- mapM (tDefinicaoFuncao tfun) definicoesFuncoes

    -- 3. Verifica variáveis globais duplicadas
    tvar <- tVariavel [] variaveisGlobais

    -- 4. Analisa o bloco principal (assumindo retorno Void e acesso às globais)
    blocoPrincipal' <- tBloco TVoid tfun tvar blocoPrincipal

    return (Prog tfun definicoesFuncoes' tvar blocoPrincipal')