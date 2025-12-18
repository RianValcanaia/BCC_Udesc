------------------------------------------
{-
Monadas:
return :: a -> M a
>>:: M a -> M b -> M b
>>=:: M a -> a -> M b -> Mb

putStr :: String -> IO  - pega uma string e exibe na tela;
getLine :: IO String - pega uma string de input do usuario
main :: IO String
-}

{-
main = putStrLn "Qual o seu nome?" >> getLine >>= \n -> putStrLn ("Ola " ++n++"\nQue nome bonito!")

main2 = do {putStr "Qual o seu nome?\n";
          nome <- getLine;
            putStr ("Ola " ++nome++ "\n")}

fat 0 = 1
fat n = n * fat(n-1)
fatorial = do {putStr "Digite um numero: ";
              n <- getLine;
              print (fat(read n))}

-}
------------------------------------------
import System.IO
main = do putStr "Qual o seu nome?"
          hFLush Stdout
          n <- getLine
          putStr ("Alo" ++n++ "\n")
