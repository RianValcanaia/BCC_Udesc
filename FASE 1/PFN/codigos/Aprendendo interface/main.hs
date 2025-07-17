import System.IO

main = do {putStr "Qual o seu nome? ";
           hFlush stdout;
           n <- getLine;
           putStr ("Alo " ++ n ++ "\n")}

-- não está funcionando compilador com ghc??????
