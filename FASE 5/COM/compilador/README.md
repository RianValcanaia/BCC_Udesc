<div align="center" id="topo">

<img src="https://media.giphy.com/media/iIqmM5tTjmpOB9mpbn/giphy.gif" width="200px" alt="Gif animado"/>

# <code><strong> Compilador da Linguagem j-- para JVM </strong></code>

<em>Implementação de um compilador completo (Léxico, Sintático, Semântico e Geração de Código) para a Máquina Virtual Java utilizando Haskell.</em>

[![Haskell Usage](https://img.shields.io/badge/Haskell-100%25-purple?style=for-the-badge&logo=haskell)]()
[![Status](https://img.shields.io/badge/Status-Concluído-green?style=for-the-badge)]()
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Visite%20meu%20perfil-blue?style=for-the-badge&logo=linkedin)](SEU_LINK_LINKEDIN_AQUI)

</div>

## Índice

- [📌 Objetivos](#-objetivos)
- [📥 Entradas do sistema](#-entradas-do-sistema)
- [🧱 Estruturas de Dados](#-estruturas-de-dados)
- [🧰 Funcionalidades](#-funcionalidades)
- [📊 Exemplo de Execução](#-exemplo-de-execução)
- [📂 Como executar](#-como-executar)
- [👨‍🏫 Envolvidos](#-envolvidos)
- [📅 Curso](#-curso)
- [📄 Código-fonte](#-código-fonte)

## 📌 Objetivos

* Implementar um compilador para a linguagem definida na disciplina, suportando tipos `int`, `double` e `string`.
* Utilizar **Alex** e **Happy** para a construção dos analisadores léxico e sintático.
* Realizar a **análise semântica**, incluindo verificação de tipos, escopo e coerção automática (ex: `int` para `double`).
* Gerar código assembly **Jasmin** (`.j`) para execução na JVM.

[⬆ Voltar ao topo](#topo)

## 📥 Entradas do sistema

* O compilador recebe arquivos de texto com a extensão `.j--` contendo o código fonte na linguagem definida.
* A gramática suporta declaração de funções, variáveis, estruturas de controle (`if`, `while`) e operações aritméticas/lógicas.

[⬆ Voltar ao topo](#topo)

## 🧱 Estruturas de Dados

### 🔸 `RI (Representação Intermediária)`

Módulo `RI.hs` que define a Árvore Sintática Abstrata (AST)

```haskell
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
    deriving Show% 
```

### 🔸 `Tokens`

Módulo Token.hs que define as unidades atômicas identificadas pelo analisador léxico:

```haskell
data Token
    -- Tipos
    = TINT
    | TSTRING
    | TDOUBLE
    | TVOID

    -- Literais e Identificadores 
    | CINT Int
    | CDOUBLE Double
    | LITERAL String
    | ID String

    -- Palavras-chave 
    | TIF
    | TELSE
    | TWHILE
    | TREAD
    | TPRINT
    | TRETURN

    -- Pontuação
    | SEMICOLON   -- ;
    | LPAR        -- (
    | RPAR        -- )
    | LCBRAK      -- {
    | RCBRAK      -- }
    | COMMA       -- ,

    -- Operadores aritméticos
    | ADD         -- +
    | SUB         -- -
    | MUL         -- *
    | DIV         -- /

    -- Operadores relacionais e atribuição
    | MAJEQ       -- >=
    | MINEQ       -- <=
    | MINOR       -- <
    | MAJOR       -- >
    | EQUAL       -- ==
    | ATRIB       -- =
    | NEQUAL      -- /=

    -- Operadores logicos
    | NOT         -- !
    | AND         -- &&
    | OR          -- ||

    deriving (Eq, Show)
```

[⬆ Voltar ao topo](#topo)

## 🧰 Funcionalidades

### 🔹 Fases do Compilador

-   Análise Léxica (Lex.x): Tokenização do código fonte ignorando espaços em branco e comentários.

-   Análise Sintática (Parser.y): Geração da AST bruta a partir dos tokens.

-   Análise Semântica (Semantico.hs):

    -   Verificação de tipos incompatíveis.

    -   Verificação de variáveis/funções não declaradas ou duplicadas.

    -   Inserção de nós de coerção (IntDouble, DoubleInt) na AST.

-   Geração de Código (Intermediario.hs): Tradução da AST tipada para mnemônicos Jasmin.

🔸 Recursos Suportados

-   Tipos: int, double, string.

-   Coerção: Promoção automática de int para double em operações mistas.

-   Controle de Fluxo: Labels automáticos para if/else e while.

-   IO: Comandos read (não testado, pois não foi cobrado para) e print (via System.out).

[⬆ Voltar ao topo](#topo)

## 📊 Exemplo de Execução
1. Entrada (`teste.j--`)
    ```txt
    {
    int a;
    a = 10;
    print(a);
    }
    ``` 

2. Processamento:

    -   O Parser gera a árvore.

    -   O Semântico valida e tipa a árvore.

    -   O Gerador produz o arquivo Program.j.

3. Saída (Program.j):
    ```assembly
    .class public Program
    .super java/lang/Object

    .method public <init>()V
        aload_0
        invokenonvirtual java/lang/Object/<init>()V
        return
    .end method

    .method public static main([Ljava/lang/String;)V
        .limit stack 20
        .limit locals 2
        bipush 10
        istore 1
        getstatic java/lang/System/out Ljava/io/PrintStream;
        iload 1
        invokevirtual java/io/PrintStream/println(I)V
        return
    .end method
    ```

[⬆ Voltar ao topo](#topo)

## 📂 Como executar

Para compilar e rodar o projeto, certifique-se de ter o GHC (Glasgow Haskell Compiler) e as ferramentas alex e happy instaladas.

1. Gerar os analisadores:
```bash
alex Lex.x && happy Parser.y
``` 

2. Compilar o projeto:
```bash
ghc Main.hs -o compilador
``` 
3. Executar:
```bash
./compilador arquivo_teste.j--
```
4. Isso gerará um arquivo .j.
```bash
java -jar jasmin.jar Program.j
```
Isso gerará o arquivo .class.

5. Rodar na JVM:
```bash
java Program
```

[⬆ Voltar ao topo](#topo)

## 👨‍🏫 Envolvidos

*   **Professor**: Cristiano Damiani Vasconcellos
*   **Estudantes**:
    *   [Rian Carlos Valcanaia](https://github.com/RianValcanaia)
    *   [Matheus Azevedo de Sá](https://github.com/Math-Az)

[⬆ Voltar ao topo](#topo)

## 📅 Curso

*   **Universidade**: Universidade do Estado de Santa Catarina (UDESC)
*   **Disciplina**: Compiladores
*   **Semestre**: 5º

[⬆ Voltar ao topo](#topo)

## 📄 Código-fonte

🔗 [https://github.com/RianValcanaia/COM_Compilador](https://github.com/RianValcanaia/COM_Compilador)

[⬆ Voltar ao topo](#topo)