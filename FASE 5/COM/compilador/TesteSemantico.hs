module Main where

import System.Directory (listDirectory, doesDirectoryExist)
import System.FilePath (takeExtension, (</>))
import Control.Exception (try, evaluate, SomeException)
import System.IO (hFlush, stdout)

-- Importações do seu projeto
import Parser (calc)      
import qualified Lex as L 
import RI (Programa)      
import Semantico (tProg, Result(..)) -- Importa o Semântico

main :: IO ()
main = do
    putStr "Informe o diretório com os testes (ex: ./testes): "
    hFlush stdout
    dir <- getLine

    existe <- doesDirectoryExist dir
    if not existe
        then putStrLn $ "Erro: O diretório '" ++ dir ++ "' não existe."
        else executarBateriaTestes dir

executarBateriaTestes :: FilePath -> IO ()
executarBateriaTestes dir = do
    arquivos <- listDirectory dir
    let arquivosTeste = filter (\f -> takeExtension f == ".j--") arquivos 
    
    if null arquivosTeste
        then putStrLn "Nenhum arquivo de teste encontrado."
        else do
            putStrLn $ "\nIniciando bateria com " ++ show (length arquivosTeste) ++ " testes...\n"
            putStrLn "---------------------------------------------------"
            mapM_ (rodarTesteIndividual dir) arquivosTeste
            putStrLn "---------------------------------------------------"
            putStrLn "Fim da execução."

rodarTesteIndividual :: FilePath -> FilePath -> IO ()
rodarTesteIndividual dir arquivo = do
    let caminhoCompleto = dir </> arquivo
    
    conteudoEither <- try (readFile caminhoCompleto) :: IO (Either SomeException String)
    
    case conteudoEither of
        Left erroIO -> putStrLn $ "[ERRO LEITURA] " ++ arquivo ++ ": " ++ show erroIO
        Right conteudo -> do
            -- 1. Executa Parser
            resultadoParser <- try (evaluate (calc (L.alexScanTokens conteudo))) :: IO (Either SomeException Programa)
            
            case resultadoParser of
                Left erro -> do
                    putStrLn $ "[FALHA SINTÁTICA] " ++ arquivo 
                    putStrLn $ "   >>> " ++ show erro
                    putStrLn ""

                Right ast -> do
                    -- 2. Executa Semântico
                    let resultadoSemantico = tProg ast
                    
                    case resultadoSemantico of
                        Result (temErroFatal, logs, astTipada) -> do
                            if temErroFatal
                            then do
                                putStrLn $ "[FALHA SEMÂNTICA] " ++ arquivo
                                putStrLn "   >>> Erros Encontrados:"
                                putStrLn logs
                            else do
                                -- Verifica se tem warnings
                                if not (null logs)
                                then do
                                    putStrLn $ "[OK COM AVISOS]   " ++ arquivo
                                    putStrLn "   >>> Avisos:"
                                    putStrLn logs
                                else 
                                    putStrLn $ "[OK]              " ++ arquivo
                                
                                -- Se quiser ver a AST final com as coerções (IntDouble), descomente:
                                -- print astTipada 
                                -- putStrLn ""