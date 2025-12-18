-- Rian Carlos Valcanaia e Matheus Azevedo de Sá, 27 nov 2023
{-
Departamento de Ciência da Computação
Programação Funcional - Trabalho
O objetivo deste trabalho é definir uma função que, dado um documento (arquivo .txt), gere um
índice de linhas em que as palavras ocorrem nesse documento, as informações (palavras e lista de
linhas em que ocorrem) devem ser armazenada em uma árvore binária de pesquisa declarada como:
type Word’ = String
type Line = String
type Doc = String
data Tree = Node Word’ [Int] Tree Tree | Leaf deriving Show
A função makeIndexTree deve combinar todas as funções definidas nos itens abaixo retornando a
árvore de índices.
makeIndexTree :: Doc →Tree
O problema de gerar os índices pode ser dividido nos seguintes subproblemas:
a) Separar o documento em linhas: lines :: Doc → [Line]
b) Numerar as linhas do documento: numLines :: [Line] → [(Int,Line)]
c) Associar a cada ocorrência de uma palavra do documento o número da linha em que essa
palavra ocorre: allNumWords :: [(Int,Line)] → [(Int,Word’)]
d) Inserir elementos em uma lista ordenada, o elemento deve ser inserido em uma posição que
mantenha a lista resultante ordenada. Caso a lista já contenha o elemento não deve ocorrer a
inserção:
insOrd :: a → [a] → [a]
e) Inserir uma palavra e linha de ocorrência na árvore (Tree), caso a palavra já tenha sido
inserida apenas a linha deve ser adicionada a lista de linhas relacionadas com a palavra.
Deve ser usada a função definida no item anterior para essa tarefa:
ins :: Word’ → Int → Tree → Tree
f) Percorrer a lista com as duplas de palavras e linhas inserido cada uma delas na árvore:
mIndexTree :: [(Int,Word’)] →Tree
A impressão das palavras e índices deve ser feita percorrendo a árvore em ordem.
Observações:
As seguintes funções são definidas na biblioteca padrão de Haskell:
lines :: String → [String] -- Divide um texto em linhas
words :: String → [String] -- Divide uma linha em palavras
-}

import System.IO
import Data.Char
import Data.List

-- Numera as linhas do arquivo
numeraLinhas a [] = []
numeraLinhas a (h:t) = (a,h) : numeraLinhas (a + 1) t

-- Lista ocorrencias de palavra
associaPalavraLinha [] = []
associaPalavraLinha ((n, h):t) = associaPalavraLinhaAux n (words h) ++ associaPalavraLinha t
associaPalavraLinhaAux n [] = []
associaPalavraLinhaAux n (h:t) = (h, n) : associaPalavraLinhaAux n t

-- Filtrar somente caracateres Alfabeticos
filtrar [] = []
filtrar ((h,n):t) = (filter isAlpha h,n):filtrar t

-- ÁRVORE ---------------------------------------------------------------
data Arvore a = No a (Arvore a) (Arvore a) | Folha deriving Show

insereOrdenado a [] = [a]
insereOrdenado a (x:xs) | a == x = (x:xs)
                        | a < x = a:(x:xs)
                        |otherwise = x:insereOrdenado a (xs)

-- Insere elemento na Arvore
insereElemento Folha (p, l) = No (p, [l]) Folha Folha
insereElemento (No (f, s) esquerda direita) (p, l) | f == p = (No (f, insereOrdenado l s) esquerda direita)
                                                   | f < p = (No (f, s) esquerda (insereElemento direita (p, l)))
                                                   | otherwise = (No (f, s) (insereElemento esquerda (p, l)) direita)

--makeIndexTree
makeIndex arvore [] = arvore
makeIndex arvore ((p, l):xs) = makeIndex (insereElemento arvore (p,l)) xs

imprimeOrdenado Folha = []
imprimeOrdenado (No (p, l) esquerda direita) = imprimeOrdenado (esquerda) ++ [(p,l)] ++ imprimeOrdenado (direita)

-- MAIN ------------------------------------------------------------------
main = do putStrLn "Digite o nome do arquivo txt para ser lido."
          hFlush stdout
          arquivo <- getLine
          texto <- readFile arquivo
          
          --print (numeraLinhas 1 (lines (map toLower texto)))
          --print (associaPalavraLinha (numeraLinhas 1 (lines (map toLower texto))))
          print (imprimeOrdenado (makeIndex Folha ((filtrar (associaPalavraLinha (numeraLinhas 1 (lines (map toLower texto))))))))

