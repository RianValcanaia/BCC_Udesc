{- 
   ta ok
   Definição da Representação Intermediária (RI) ou Árvore Sintática Abstrata (AST).
   Contém os tipos de dados algébricos que modelam a estrutura do programa,
   como Expressões (Expr), Comandos (Comando), Funções e o Programa completo.
-}

module RI where

type Id = String

-- Tipos básicos da linguagem
data Tipo 
    = TDouble 
    | TInt 
    | TString 
    | TVoid
    deriving (Show, Eq)

-- Constantes numéricas
data TCons 
    = CDouble Double 
    | CInt Int 
    deriving Show

-- Expressões aritméticas e chamadas de função
data Expr
    = Add Expr Expr
    | Sub Expr Expr
    | Mul Expr Expr
    | Div Expr Expr 
    | Neg Expr
    | Const TCons
    | IdVar String
    | Chamada Id [Expr]
    | Lit String
    | IntDouble Expr
    | DoubleInt Expr
    deriving Show

-- Expressões relacionais
data ExprR
    = Req Expr Expr
    | Rdif Expr Expr
    | Rlt Expr Expr
    | Rgt Expr Expr
    | Rle Expr Expr
    | Rge Expr Expr
    deriving Show

-- Expressões lógicas
data ExprL
    = And ExprL ExprL
    | Or ExprL ExprL
    | Not ExprL
    | Rel ExprR
    deriving Show

-- Variáveis com tipo e posição (offset para a pilha/stack frame)
data Var = Id :#: (Tipo, Int)
    deriving Show

-- Cabeçalho de função: nome -> (parâmetros, tipoRetorno)
data Funcao = Id :->: ([Var], Tipo)
    deriving Show

-- Programa: lista de assinaturas, lista de defs, variáveis globais, bloco principal
data Programa = Prog [Funcao] [(Id, [Var], Bloco)] [Var] Bloco
    deriving Show

-- Bloco = lista de comandos
type Bloco = [Comando]

-- Comandos
data Comando
    = If ExprL Bloco Bloco
    | While ExprL Bloco
    | Atrib Id Expr
    | Leitura Id
    | Imp Expr
    | Ret (Maybe Expr)
    | Proc Id [Expr]
    deriving Show