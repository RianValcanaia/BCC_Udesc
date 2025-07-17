import Data.List
import Data.Char
import System.IO

numLinhas xs = numLinhasAux 1 xs
numLinhasAux a [] = []
numLinhasAux a (x:xs) = (x,a): numLinhasAux (a+1) xs

allNumWords [] = []
allNumWords ((x,n):xs) = allNumWordsAux n (words x) ++ allNumWords xs
allNumWordsAux _ [] = []
allNumWordsAux n (x:xs) = (x,n): allNumWordsAux n xs

filtrar [] = []
filtrar ((x,n):xs) = (filter isAlpha (x), n): filtrar xs

juntar [] = []
juntar ((x,n):xs) = (x,n:juntarAux x xs):juntar (drop tam xs)
    where tam = length (juntarAux x xs)
juntarAux a [] = []
juntarAux a ((x,n):xs) = if a == x then n:juntarAux a xs else juntarAux a xs

-- falta terminar
-- imprime ((x,n):xs) = do putStr x
--                         putStr n

main = do putStrLn "Digite o arquivo:"
          hFlush stdout
          arquivo <- getLine
          texto <- readFile arquivo
          print (juntar(sort (filtrar (allNumWords (numLinhas (lines (map toLower texto)))))))
