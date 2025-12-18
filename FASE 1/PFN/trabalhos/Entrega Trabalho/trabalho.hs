import System.IO
import Data.Char
import Data.List

--ImprimePalavras -- imprimePalavras (words texto)
imprimePalavras [] = putStr "\n\n"
imprimePalavras (p:ps) = do putStr (p++ "\n")
                            imprimePalavras ps

--NumLines
a = 0
numLines (x:xs) = aux 1 (x:xs)
aux n [] = []
aux n (x:xs) = (n,x):aux (n+1) xs

--allNumWords
allNumWords [] = []
allNumWords ((n,x):xs) = aux2 n (words x) ++ allNumWords xs
aux2 _ [] = []
aux2 n (x:xs) = (n,x): aux2 n xs

--Filtrar
filtrar [] = []
filtrar ((n,x):xs) = (n, filter isAlphaNum x):filtrar xs


--Inverte
inverte [] = []
inverte ((n,x):xs) = (x,n):inverte xs

--removerElementos
almalgamate [] = []
almalgamate ((x,n):xs) = (x,n:ax):almalgamate (drop tam xs)
    where ax = aux3 x xs
          tam = length ax
aux3 a [] = []
aux3 a ((x,n):xs) = if a == x then n:aux3 a xs else aux3 a xs

--shorten
shorten [] = []
shorten ((x,n):xs) = (x,aux4 n): shorten xs
aux4 [] = []
aux4 (x:xs) = if notElem x xs then x:aux4 xs else aux4 xs

--imprimi
imprime [] = putStr "\n"
imprime ((x,n):xs) = do putStr x
                        putStr (take (20 - (length x))(repeat ' '))
                        print n
                        imprime xs

--leitura de arquivo TXT
main = do putStr "Arquivo: "
          hFlush stdout  --limpa o buffer
          arquivo <- getLine
          texto <- readFile arquivo
          let minusculo = map toLower texto
          imprime (shorten (almalgamate (sort (inverte (filtrar (allNumWords (numLines (lines (map toLower texto))))))))) --lembrar do lines
