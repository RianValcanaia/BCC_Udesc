{- 
   -- Ta ok
   Módulo auxiliar que define o tipo de dado algébrico 'Token'.
   Representa as unidades atômicas da linguagem (palavras-chave, operadores, literais)
   que são geradas pelo Analisador Léxico e consumidas pelo Analisador Sintático.
-}

module Token where

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

    -- Pontuacao
    | SEMICOLON   -- ;
    | LPAR        -- (
    | RPAR        -- )
    | LCBRAK      -- {
    | RCBRAK      -- }
    | COMMA       -- ,

    -- Operadores aritmeticos
    | ADD         -- +
    | SUB         -- -
    | MUL         -- *
    | DIV         -- /

    -- Operadores relacionais e atribuicao
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


