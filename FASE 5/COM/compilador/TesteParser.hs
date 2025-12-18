module Main where

import System.Directory (listDirectory, doesDirectoryExist)
import System.FilePath (takeExtension, (</>))
import Control.Exception (try, evaluate, SomeException)
import Control.Monad (forM_)
import System.IO (hFlush, stdout)

-- Importações do seu projeto
import Parser (calc)      -- Importa a função do Parser
import qualified Lex as L -- Importa o Lexer
import RI (Programa)      -- Importa o tipo da AST para o Show funcionar

-- Função Principal
main :: IO ()
main = do
    putStr "Informe o diretório com os testes (ex: ./testes): "
    hFlush stdout
    dir <- getLine

    existe <- doesDirectoryExist dir
    if not existe
        then putStrLn $ "Erro: O diretório '" ++ dir ++ "' não existe."
        else executarBateriaTestes dir

-- Executa a lógica de varredura e teste
executarBateriaTestes :: FilePath -> IO ()
executarBateriaTestes dir = do
    arquivos <- listDirectory dir
    -- Filtra apenas arquivos que terminam com a extensão desejada
    let arquivosTeste = filter (\f -> takeExtension f == ".j--") arquivos 
    
    if null arquivosTeste
        then putStrLn "Nenhum arquivo de teste encontrado neste diretório."
        else do
            putStrLn $ "\nIniciando bateria com " ++ show (length arquivosTeste) ++ " testes...\n"
            putStrLn "---------------------------------------------------"
            
            mapM_ (rodarTesteIndividual dir) arquivosTeste
            
            putStrLn "---------------------------------------------------"
            putStrLn "Fim da execução."

-- Roda um único arquivo e trata exceções
rodarTesteIndividual :: FilePath -> FilePath -> IO ()
rodarTesteIndividual dir arquivo = do
    let caminhoCompleto = dir </> arquivo
    
    conteudoEither <- try (readFile caminhoCompleto) :: IO (Either SomeException String)
    
    case conteudoEither of
        Left erroIO -> 
            putStrLn $ "[ERRO DE LEITURA] " ++ arquivo ++ ": " ++ show erroIO
            
        Right conteudo -> do
            resultado <- try (evaluate (calc (L.alexScanTokens conteudo))) :: IO (Either SomeException Programa)
            
            case resultado of
                Left erro -> do
                    putStrLn $ "[FALHOU] " ++ arquivo 
                
                -- AQUI ESTÁ A MUDANÇA: Capturamos 'ast' e usamos 'print'
                Right ast -> do
                    putStrLn $ "[OK]     " ++ arquivo
                    print ast
                    putStrLn "" -- Linha em branco para separar

teste :: IO ()
teste = do 
    putStr "Informe o nome do arquivo "
    arquivo <- getLine
    s <- readFile arquivo
    print (calc (L.alexScanTokens s))
