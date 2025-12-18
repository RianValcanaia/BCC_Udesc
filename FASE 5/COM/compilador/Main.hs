module Main where

import System.Environment (getArgs)
import qualified Lex as L      
import Parser (calc)           
import Semantico (tProg, Result(..)) 
import RI (Programa)           
import Intermediario (gerar)

main :: IO ()
main = do
    args <- getArgs
    case args of
        [] -> putStrLn "Uso: ./teste_semantico <arquivo.j-->"
        (arquivo:_) -> processarArquivo arquivo

processarArquivo :: FilePath -> IO ()
processarArquivo fileName = do
    putStrLn $ "\n=== Lendo arquivo: " ++ fileName ++ " ===\n"
    
    -- 1. Leitura
    conteudo <- readFile fileName
    
    -- 2. Léxico
    let tokens = L.alexScanTokens conteudo
    -- putStrLn "--- Tokens ---"
    -- print tokens -- Descomente se quiser ver a lista de tokens

    -- 3. Sintático
    let astBruta = calc tokens
    putStrLn "--- 1. AST Bruta (Saída do Parser) ---"
    print astBruta
    putStrLn "\n---------------------------------------------------"

    -- 4. Semântico
    putStrLn "--- 2. Análise Semântica ---"
    case tProg astBruta of
        Result (erroFatal, logs, astTipada) -> do
            -- Imprime as mensagens (Erros e Warnings acumulados)
            if null logs 
                then putStrLn "Nenhum aviso ou erro encontrado."
                else putStrLn logs
            
            putStrLn "---------------------------------------------------"
            
            if erroFatal then do
                putStrLn ">>> FALHA: Erros semânticos impedem a compilação."
            else do
                putStrLn ">>> SUCESSO: Análise Semântica concluída!"
                putStrLn "\n--- 3. AST Final (Com Coerções Inseridas) ---"
                -- Aqui você verá os nós IntDouble/DoubleInt que o semântico inseriu
                print astTipada

                -- ---------------------------------------------------
                -- 5. Geração de Código
                -- ---------------------------------------------------
                let nomeClasse = "Program"
                let codigoJasmin = gerar nomeClasse astTipada
                let arquivoSaida = nomeClasse ++ ".j"
                
                -- Salva o código gerado em disco
                writeFile arquivoSaida codigoJasmin
                
                putStrLn "\n---------------------------------------------------"
                putStrLn $ ">>> GERAÇÃO DE CÓDIGO: Arquivo gerado com sucesso!"
                putStrLn $ ">>> Saída: " ++ arquivoSaida
                
                -- putStrLn "\n--- 6. Código Jasmin Gerado ---"
                -- putStrLn codigoJasmin