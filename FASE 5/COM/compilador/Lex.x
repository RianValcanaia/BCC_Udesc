{
module Lex where 
import Token 
}

-- ta ok
--  Definição do Analisador Léxico utilizando a ferramenta Alex.
--  Define expressões regulares para reconhecer números, identificadores, palavras-chave
--  e símbolos da linguagem, ignorando espaços em branco.
--  ENTRADA (na função alexScanTokens):
--  - String: O conteúdo textual completo do código fonte.
--  SAÍDA:
--  - [Token]: Uma lista de tokens léxicos (definidos em Token.hs).


%wrapper "basic" 

---- Definicoes 
-- $ apelidos simples 
$digit = [0-9] 

---- Expressões Regulares 
-- @ para expressoes regulares nomeadas
@int = $digit+ 
@double = '-'?$digit+\.$digit* | \.$digit+ 
@id     = [A-Za-z]([A-Za-z] | ['_'] | $digit)* 
@literal = \"([^\"\\] | \\.)*\"

---- Regras de Tokens 
tokens :-

-- Ignorar espacoes
-- <0> - estado do analisador - aqui so tem um estado
<0> $white+ ; 

-- Tokens com Valor
<0> @int {\s -> CINT (read s)} -- converte @int para token CINT
<0> @double {\s -> CDOUBLE (parseDoubleString s)} -- converte @double para token CDOUBLE 
<0> @literal {\s -> LITERAL (read s)} -- converte @literal para token LITERAL 

-- Palavras-Chave (devem vir antes de @id para terem prioridade)
<0> "int" {\s -> TINT}  
<0> "string" {\s -> TSTRING}  
<0> "double" {\s -> TDOUBLE}  
<0> "void" {\s -> TVOID}  
<0> "if" {\s -> TIF}  
<0> "else" {\s -> TELSE} 
<0> "while" {\s -> TWHILE}  
<0> "read" {\s -> TREAD}  
<0> "print" {\s -> TPRINT}  
<0> "return" {\s -> TRETURN}  

-- Pontuação
<0> ";" {\s -> SEMICOLON}  
<0> "(" {\s -> LPAR}  
<0> ")" {\s -> RPAR}  
<0> "{" {\s -> LCBRAK}  
<0> "}" {\s -> RCBRAK}  
<0> "," {\s -> COMMA}  

<0> @id {\s -> ID s} -- converte @id para token ID 

<0> "+" {\s -> ADD}  
<0> "-" {\s -> SUB}  
<0> "*" {\s -> MUL}  
<0> "/" {\s -> DIV}  
<0> ">=" {\s -> MAJEQ}  
<0> "<=" {\s -> MINEQ}  
<0> "<" {\s -> MINOR}  
<0> ">" {\s -> MAJOR}  
<0> "==" {\s -> EQUAL}  
<0> "=" {\s -> ATRIB}  
<0> "/=" {\s -> NEQUAL}  
<0> "!" {\s -> NOT}    
<0> "&&" {\s -> AND}   
<0> "||" {\s -> OR}  

{
-- Funcao de teste: le um arquivo e imprime os tokens
testLex = do 
  putStrLn "Digite o nome do arquivo para testar:"
  fileName <- getLine
  s <- readFile fileName 
  print (alexScanTokens s) 

parseDoubleString str = case str of
  ('-':n) -> - (parseDoubleString n) 
  ('.':n) -> read ('0':str) -- trata numeros como ".5" e vira "0.5"
  n       -> read $
              if last n == '.' -- trata numeros como "5." e vira "5.0"
              then n ++ "0"
              else n -- caso normal, tudo certo
}
