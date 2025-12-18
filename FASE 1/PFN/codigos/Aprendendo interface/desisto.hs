import System.IO

--ImprimePalavras
imprimePalavras [] = putStr "\n\n"
imprimePalavras (p:ps) = do putStr (p++ "\n")
                            imprimePalavras ps
--leitura de arquivo TXT
main = do putStr "Arquivo:"
          hFlush stdout
          arquivo <- getLine
          texto <- readFile arquivo
          imprimePalavras (words texto)
          --da para usar o print aqui

