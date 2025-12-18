-- Codegen.hs

{-
    Gera assembly para JVM (Jasmin)

    NOTA IMPORTANTE DO CÓDIGO GERADO:
        - Instruções printadas devem começas com \t (para alinhar o encadeamento) e terminar com \n, sinalizando o seu fim

    NOTAS SOBRE SINTAX
    - '_' usado em parâmetros de função age como um "dont care", ele ignora o que foi passado como parâmetro
    - "do" serve para trabalhar com Monads. Ele faz com que as linhas sejam executada em sequÊncia, como numa linguagem iperativa
    - '<-' guarda o retorno de uma função em uma variável local
    - lookup: 
        - lookup id (map (\(v :#: (t, offset)) -> (v, (t, offset))) tab)
        - Faz uma busca na tabela de símbolos (procura por uma variável) e retorna (Tipo, Offset)
    - mapM
        - Mapeia uma função monádica sobre os elementos de uma lista

-}

module Intermediario where

import Control.Monad.State
import RI
import Data.List(sortBy)
import Data.Ord(comparing)

type CodegenState a = State Int a -- Definição de um novo tipo. State uma coisa em Haskell que permite que funções "carreguem" e "atualizem" um estado oculto

-- ➡️ Gera label numerado
novoLabel :: State Int String
novoLabel = do
    n <- get -- get é uma ação do State Monad. Está pegando o valor atual do estado
    put (n + 1)
    return ("L" ++ show n)

-- Auxiliares de tipo (Rian adicionou aqui, dê uma olhada aqui meu amigo Matheus)
tamTipo :: Tipo -> Int
tamTipo t | t == TDouble = 2
          | t == TVoid = 0
          | otherwise = 1 

genTab :: [Var] -> Int -> [Var]
genTab [] _ = []
genTab ((id :#: (tipo, _)) : vs) idxAtual = (id :#: (tipo, idxAtual)) : genTab vs (idxAtual + tamTipo tipo)

buscaVarTab :: [Var] -> String -> Maybe (Tipo, Int)
buscaVarTab [] id = Nothing
buscaVarTab ((idSimb :#: (tipo, idx)) : vs) id = if id == idSimb then Just (tipo, idx) else buscaVarTab vs id

buscaFunc :: [Funcao] -> String -> Maybe Funcao
buscaFunc [] _ = Nothing
buscaFunc (f@(fid :->: _) : fs) id = if id == fid then Just f else buscaFunc fs id

-- Geradores de Instruções Simples
-- ➡️📗 Instrução para gerar inteiro
genInt :: Int -> String
genInt i
    | i >= 0 && i <= 5 = "\ticonst_" ++ show i ++ "\n" -- iconst_0 a iconst_5   (mudei aqui 0<=i<=5, antes estava -1<=i<=5)
    | i >= -128 && i <= 127 = "\tbipush " ++ show i ++ "\n" -- byte push
    | otherwise = "\tldc " ++ show i ++ "\n" -- load constant

-- (Rian adicionou aqui, dê uma olhada aqui meu amigo Matheus)
genDouble :: Double -> String
genDouble d | d == 0.0 = "\tdconst_0\n"
            | d == 1.0 = "\tdconst_1\n"
            | otherwise = "\tldc2_w " ++ show d ++ "\n"  -- ldc2_w é uma instrução da JVM usada para carregar constantes de 64 bits da constant pool para a pilha de operandos

genOp :: Tipo -> String
genOp t = case t of
              TInt -> "\ti"
              TDouble -> "\td"
              TString -> "\ta"
              _ -> error "genOp: tipo invalido"

genTipoAss :: Tipo -> String
genTipoAss t | t == TInt = "I"
             | t == TDouble = "D"
             | t == TString = "Ljava/lang/String;"
             | t == TVoid = "V"

genAssinatura :: [Var] -> Tipo -> State Int String
genAssinatura params tRet = pure ("(" ++ concatMap (\(_ :#: (tipo, _)) -> genTipoAss tipo) params ++ ")" ++ genTipoAss tRet)

-- ❤️❤️❤️ CORAÇÃO DA GERAÇÃO DE CÓDIGO ❤️❤️❤️
genExpr :: [Var] -> [Funcao] -> Expr -> State Int (Tipo, String)
-- genExpr :: Nome -> Tabela de Variáveis -> Lista de funções declaras -> Expressão que será traduzida -> CodegenState permite a geração de labels (Tipo do resultado, Código gerado) 

-- 📗 Traduação de CONSTANTES
genExpr tab fun (Const (CInt i)) = pure (TInt, genInt i)
genExpr tab fun (Const (CDouble d)) = pure (TDouble, genDouble d) 

-- 📗 Tradução de OPERAÇÕES ARITMÉTICA BINÁRIAS (Add, Sub, Mul, Div) -- "Looping" (função recursiva) que resolve uma expressão até chegar em uma operação, que é enviada para genOp, onde é traduzida em código
genExpr tab fun (Add e1 e2) = do
    (t1, e1') <- genExpr tab fun e1  -- t1, e1' são variáveis locais que recebem o resultado da chama de função genExpr c tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (t1, e1' ++ e2' ++ genOp t1 ++ "add\n") -- note que não há uso de \t e \n pois não é aqui que essa operação é resolvida, é na função genOp.

genExpr tab fun (Sub e1 e2) = do
    (t1, e1') <- genExpr tab fun e1 
    (t2, e2') <- genExpr tab fun e2
    return (t1, e1' ++ e2' ++ genOp t1 ++ "sub\n")

genExpr tab fun (Mul e1 e2) = do
    (t1, e1') <- genExpr tab fun e1 
    (t2, e2') <- genExpr tab fun e2
    return (t1, e1' ++ e2' ++ genOp t1 ++ "mul\n")

genExpr tab fun (Div e1 e2) = do
    (t1, e1') <- genExpr tab fun e1 
    (t2, e2') <- genExpr tab fun e2
    return (t1, e1' ++ e2' ++ genOp t1 ++ "div\n")

-- 📗 Tradução de OPERAÇÕES ARITMÉTICA UNÁRIA (Neg)
genExpr tab fun (Neg e) = do
    (t, e') <- genExpr tab fun e
    return (t, e' ++ genOp t ++ "neg\n")


-- 📗 Tradução de VARIÁVEIS - Busca o id da variável na tabela e retorna o seu tipo e o seu offset. Depois, carrega na memória.
genExpr tab fun (IdVar id) = case buscaVarTab tab id of
                                Just (t, idx) -> pure (t, genOp t ++ "load " ++ show idx ++ "\n")
                                Nothing -> error ("genExpr: variavel '" ++ id ++ "' nao encontrada")

genExpr tab fun (Lit l) = pure (TString, "\tldc \"" ++ l ++ "\"\n")

genExpr tab fun (Chamada id args) = do 
    codArgs <- mapM (genExpr tab fun) args
    let codConcat = concatMap snd codArgs
    case buscaFunc fun id of
        Nothing -> error ("genExpr: funcao '" ++ id ++ "' nao definida")
        Just (_ :->: (params, tRet)) -> do 
            ass <- genAssinatura params tRet
            let nomeClasse = "Program" -- Pode ser parametrizado
            pure (tRet, codConcat ++ "\tinvokestatic " ++ nomeClasse ++ "/" ++ id ++ ass ++ "\n")

-- 📗 Tradução de COERÇÃO DE TIPOS (int <-> double)
{- 
    Conversão        AST         Assembly Jvm
    int -> double    IntDouble   i2d
    double -> int    DoubleInt   d2i
-}
genExpr tab fun (IntDouble e1) = do -- Tradução de Int -> Double
    (t1, e1') <- genExpr tab fun e1
    pure (TDouble, e1' ++ "\ti2d\n")  --O tipo final da expressão é TDouble

genExpr tab fun (DoubleInt e1) = do  -- Tradução de Double -> Int
    (t1, e1') <- genExpr tab fun e1  
    pure (TInt, e1' ++ "\td2i\n")

-- ➡️📘 Tradução de OPERADORES RELACIONAIS 
genRel :: Tipo -> Tipo -> String -> String -> String
genRel t1 t2 v op | t1 == TDouble = "\tdcmpg\nif" ++ op ++ " " ++ v
                  | otherwise = "\tif_icmp" ++ op ++ " " ++ v

-- 📘 Tradução de RELAÇÕES (ExprR) Obs: O código não deve gerar um valor booleano, mas sim instruções de salto condicional
genExprR :: [Var] -> [Funcao] -> String -> String -> ExprR -> State Int String
genExprR tab fun v f (Req e1 e2) = do  -- Igual
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "eq" ++ "\n\tgoto " ++ f ++ "\n")

genExprR tab fun v f (Rdif e1 e2) = do  -- Diferente
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "ne" ++ "\n\tgoto " ++ f ++ "\n")

genExprR tab fun v f (Rlt e1 e2) = do  -- Menor que
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "lt" ++ "\n\tgoto " ++ f ++ "\n")

genExprR tab fun v f (Rgt e1 e2) = do  -- Maior que
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "gt" ++ "\n\tgoto " ++ f ++ "\n")

genExprR tab fun v f (Rle e1 e2) = do  -- Menor igual
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "le" ++ "\n\tgoto " ++ f ++ "\n")

genExprR tab fun v f (Rge e1 e2) = do  -- Maior igual
    (t1, e1') <- genExpr tab fun e1
    (t2, e2') <- genExpr tab fun e2
    pure (e1' ++ e2' ++ genRel t1 t2 v "ge" ++ "\ngoto " ++ f ++ "\n")

-- 📘 Tradução de EXPRESSÕES LÓGICAS
{-
    EXEMPLO

    Entrada: 
        if (x < 10 && y > 3)

    Saída: e1' ++ l1 ++ ":\n" ++ e2' =

        ; (código de e1 = x < 10) = e1' =
        iload x
        ldc 10
        if_icmpge Lfalse    ; se NÃO, pula para falso (Lfalse)
        goto L1             ; se TRUE, vai avaliar e2

        L1:                 ; = l1 ++ ":\n"
        ; (código de e2 = y > 3) = e2' =
        iload y
        ldc 3
        if_icmple Lfalse    ; se NÃO, pula para falso (Lfalse)
        goto Ltrue

    Isso tudo equivale a: e1' ++ l1 ++ ":\n" ++ e2'
-}    
genExprL :: [Var] -> [Funcao] -> String -> String -> ExprL -> State Int String
genExprL tab fun v f (And e1 e2) = do -- Tradução de And (e1 && e2)
    l1 <- novoLabel  -- Gera um rótulo intermediário (l1) para a segunda expressão lógica. O rótulo l1 serve como ponto de partida para e2
    e1' <- genExprL tab fun l1 f e1  -- Avalia e1. Se e1 for FALSO, pula para o rótulo FALSO final (f), se for VERDADEIRO, pula parav l1 para avaliar e2.
    e2' <- genExprL tab fun v f e2  -- Avalia e2. Se e2 for FALSO, pula para f. Se e2 for VERDADEIRO, pula para v.
    pure (e1' ++ l1 ++ ":\n" ++ e2')

genExprL tab fun v f (Or e1 e2) = do -- Tradução de Or (e1 || e2)
    l1 <- novoLabel 
    e1' <- genExprL tab fun v l1 e1  -- Só precisa avaliar e2 se e1 for FALSO
    e2' <- genExprL tab fun v f e2
    pure (e1' ++ l1 ++ ":\n" ++ e2')

genExprL tab fun v f (Not e1) = -- Tradução de Not (!e)  
    genExprL tab fun f v e1  -- Recursivamente, chega-se a genExprL para 'e'. Então, inverte-se os rótulos

genExprL tab fun v f (Rel e1) = -- Se for apenas uma relação simples (Ex: if (i < 10)), chama genExprR. 
    genExprR tab fun v f e1

-- 📙 Gera COMANDOS (Retorna String)
genCmd :: [Var] -> [Funcao] -> Comando -> State Int String
genCmd tab fun (Proc id args) = do 
    codArgs <- mapM (genExpr tab fun) args
    let codConcat = concatMap snd codArgs
    case buscaFunc fun id of
         Nothing -> error ("genCmd: funcao '" ++ id ++ "' nao definida")
         Just (_ :->: (params, tRet)) -> do 
             ass <- genAssinatura params tRet
             let nomeClasse = "Program"
             let pop = if tRet /= TVoid then "\tpop\n" else ""
             pure (codConcat ++ "\tinvokestatic " ++ nomeClasse ++ "/" ++ id ++ ass ++ "\n" ++ pop)

genCmd tab fun (Ret (Just e)) = do 
    (t, e') <- genExpr tab fun e
    let ret = case t of
                 TInt -> "ireturn"
                 TDouble -> "dreturn"
                 TString -> "areturn"
                 TVoid -> "return" -- Deveria ser erro, mas o semantico ja barrou
    pure (e' ++ "\t" ++ ret ++ "\n")

genCmd tab fun (Ret Nothing) = pure ("\treturn\n")

genCmd tab fun (Imp e) = do 
    (t, e') <- genExpr tab fun e
    let ps = "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
    let invoke = case t of
                    TInt -> "\tinvokevirtual java/io/PrintStream/println(I)V\n"
                    TDouble -> "\tinvokevirtual java/io/PrintStream/println(D)V\n"
                    TString -> "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n"
                    _ -> error ("genCmd: tipo para imprimir invalido")
    pure (ps ++ e' ++ invoke)

genCmd tab fun (Leitura id) = case buscaVarTab tab id of
    Nothing -> error ("genCmd: variavel '" ++ id ++ "' nao encontrada")
    Just (t, idx) -> do 
        let criaScanner = "\tnew java/util/Scanner\n\tdup\n\tgetstatic java/lang/System/in Ljava/io/InputStream;\n\tinvokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V\n"
        let readLine = "\tinvokevirtual java/util/Scanner/nextLine()Ljava/lang/String;\n"
        let parseEstore = case t of
                            TInt -> "\tinvokestatic java/lang/Integer/parseInt(Ljava/lang/String;)I\n" ++ genOp TInt ++ "store " ++ show idx ++ "\n"
                            TDouble -> "\tinvokestatic java/lang/Double/parseDouble(Ljava/lang/String;)D\n" ++ genOp TDouble ++ "store " ++ show idx ++ "\n"
                            TString -> genOp TString ++ "store " ++ show idx ++ "\n"
                            _ -> error ("genCmd: tipo de variavel invalido")
        pure (criaScanner ++ readLine ++ parseEstore)

genCmd tab fun (Atrib id e) = case buscaVarTab tab id of
    Nothing -> error ("genCmd: variavel '" ++ id ++ "' nao encontrada")
    Just (t, idx) -> do 
        (_, e') <- genExpr tab fun e
        pure (e' ++ genOp t ++ "store " ++ show idx ++ "\n")

genCmd tab fun (While e b) = do 
    li <- novoLabel
    lv <- novoLabel
    lf <- novoLabel
    e' <- genExprL tab fun lv lf e
    b' <- genBloco tab fun b
    pure (li ++ ":\n" ++ e' ++ lv ++ ":\n" ++ b' ++ "\tgoto " ++ li ++ "\n" ++ lf ++ ":\n")

genCmd tab fun (If e b1 b2) = do 
    lv <- novoLabel
    lf <- novoLabel
    le <- novoLabel
    e' <- genExprL tab fun lv lf e
    b1' <- genBloco tab fun b1
    b2' <- genBloco tab fun b2
    pure (e' ++ lv ++ ":\n" ++ b1' ++ "\tgoto " ++ le ++ "\n" ++ lf ++ ":\n" ++ b2' ++ le ++ ":\n")


-- ➡️📙 Auxiliar para genCmd tab fun (Bloco comandos) = do
genBloco :: [Var] -> [Funcao] -> [Comando] -> State Int String
genBloco tab fun [] = pure ""
genBloco tab fun (c:cs) = do 
    codCmd <- genCmd tab fun c
    codCmds <- genBloco tab fun cs
    pure (codCmd ++ codCmds)

-- Calculo de Stack/Locals e Estrutura Geral
calcLocais :: [Var] -> Int
calcLocais [] = 0
calcLocais ((_ :#: (tipo, _)) : ls) = tamTipo tipo + calcLocais ls

-- ➡️📕 Gera cabeçalho
genCab :: String -> State Int String
genCab nome = return (".class public " ++ "Program" ++ 
                      "\n.super java/lang/Object\n\n.method public <init>()V\n\taload_0\n\tinvokenonvirtual java/lang/Object/<init>()V\n\treturn\n.end method\n\n")

genMethodCab :: String -> String -> Int -> Int -> String
genMethodCab fid ass numStack numLocais = ".method public static " ++ fid ++ ass ++ "\n\t.limit stack " ++ show numStack ++ "\n\t.limit locals " ++ show numLocais ++ "\n"

genFunc :: String -> (Id, [Var], Bloco) -> [Funcao] -> State Int String
genFunc nomeClasse (fid, locs, bloco) tfun = do 
    let tabVar = genTab locs 0
    let numLocais = calcLocais locs
    let numStack = 20
    
    (ass, tRet) <- case buscaFunc tfun fid of
            Nothing -> pure ("()", TVoid)
            Just (_ :->: (params, r)) -> do
                s <- genAssinatura params r
                pure (s, r)
    
    bloco' <- genBloco tabVar tfun bloco
    
    let retFinal = if tRet == TVoid then "\treturn\n" else ""
    
    pure (genMethodCab fid ass numStack numLocais ++ bloco' ++ retFinal ++ ".end method\n\n")

-- 📕 Estrutura Principal
genMain :: String -> [Var] -> Bloco -> [Funcao] -> State Int String
genMain nomeClasse tloc bloco tfun = do 
    let tabVar = genTab tloc 1 -- Começa do 1 pois 0 é args
    let numLocais = 1 + calcLocais tloc
    let numStack = 20
    bloco' <- genBloco tabVar tfun bloco
    pure (genMethodCab "main" "([Ljava/lang/String;)V" numStack numLocais ++ bloco' ++ "\treturn\n.end method\n\n")

genProg :: String -> Programa -> State Int String
genProg nomeClasse (Prog tfun funcs tloc main) = do 
    codCab <- genCab nomeClasse
    codFunc <- mapM (\f -> genFunc nomeClasse f tfun) funcs
    codMain <- genMain nomeClasse tloc main tfun
    pure (codCab ++ concat codFunc ++ codMain)

-- 🫦 Função principal
gerar :: String -> Programa -> String
gerar nome p = fst $ runState (genProg nome p) 0