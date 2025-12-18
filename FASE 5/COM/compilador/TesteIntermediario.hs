module Main where

import System.Directory (listDirectory, doesDirectoryExist, createDirectoryIfMissing)
import System.FilePath (takeExtension, takeBaseName, (</>), replaceExtension)
import Control.Exception (try, evaluate, SomeException)
import System.IO (hFlush, stdout)

-- Importações do seu compilador
import Parser (calc)      
import qualified Lex as L 
import RI (Programa)      
import Semantico (tProg, Result(..)) 
import Intermediario (gerar) -- Importa o gerador

main :: IO ()
main = do
    putStr "Informe o diretório com os testes (ex: ./testes): "
    hFlush stdout
    dir <- getLine

    existe <- doesDirectoryExist dir
    if not existe
        then putStrLn $ "Erro: O diretório '" ++ dir ++ "' não existe."
        else executarGeracao dir

executarGeracao :: FilePath -> IO ()
executarGeracao dir = do
    arquivos <- listDirectory dir
    -- Filtra arquivos fonte (ajuste a extensão se necessário)
    let arquivosTeste = filter (\f -> takeExtension f == ".j--") arquivos 
    
    if null arquivosTeste
        then putStrLn "Nenhum arquivo .j-- encontrado."
        else do
            -- Cria a pasta de saída: ./testes/saida
            let dirSaida = dir </> "saida"
            createDirectoryIfMissing True dirSaida
            
            putStrLn $ "\nProcessando " ++ show (length arquivosTeste) ++ " arquivos..."
            putStrLn $ "Saída será gerada em: " ++ dirSaida
            putStrLn "---------------------------------------------------"
            
            mapM_ (processarArquivo dir dirSaida) arquivosTeste
            
            putStrLn "---------------------------------------------------"
            putStrLn "Processamento concluído."

processarArquivo :: FilePath -> FilePath -> FilePath -> IO ()
processarArquivo dirEntrada dirSaida arquivo = do
    let caminhoCompleto = dirEntrada </> arquivo
    
    -- Tenta ler
    conteudoEither <- try (readFile caminhoCompleto) :: IO (Either SomeException String)
    
    case conteudoEither of
        Left erroIO -> putStrLn $ "[ERRO LEITURA] " ++ arquivo
        Right conteudo -> do
            -- 1. Parser
            resultadoParser <- try (evaluate (calc (L.alexScanTokens conteudo))) :: IO (Either SomeException Programa)
            
            case resultadoParser of
                Left erro -> putStrLn $ "[ERRO SINTÁTICO] " ++ arquivo ++ " (Arquivo .j ignorado)"
                Right ast -> do
                    -- 2. Semântico
                    let resultadoSemantico = tProg ast
                    
                    case resultadoSemantico of
                        Result (temErroFatal, logs, astTipada) -> do
                            if temErroFatal
                            then do
                                -- Se tem erro fatal, NÃO gera código
                                putStrLn $ "[ERRO SEMÂNTICO] " ++ arquivo
                                -- Opcional: imprimir logs se quiser debugar
                                -- putStrLn logs 
                            else do
                                -- Se passou (com ou sem warnings), GERA O CÓDIGO
                                
                                -- Define o nome da classe igual ao nome do arquivo (sem extensão)
                                let nomeClasse = takeBaseName arquivo
                                
                                -- 3. Geração de Código
                                -- Precisamos tratar exceções na geração também (caso genOp falhe, etc)
                                resultadoGeracao <- try (evaluate (gerar nomeClasse astTipada)) :: IO (Either SomeException String)
                                
                                case resultadoGeracao of
                                    Left erroGen -> 
                                        putStrLn $ "[ERRO INTERNO]   " ++ arquivo ++ ": " ++ show erroGen
                                    
                                    Right codigoJasmin -> do
                                        let nomeArquivoSaida = replaceExtension arquivo ".j"
                                        let caminhoSaida = dirSaida </> nomeArquivoSaida
                                        
                                        writeFile caminhoSaida codigoJasmin
                                        
                                        if not (null logs)
                                            then putStrLn $ "[GERADO C/ AVISO] " ++ arquivo ++ " -> " ++ nomeArquivoSaida
                                            else putStrLn $ "[GERADO SUCESSO]  " ++ arquivo ++ " -> " ++ nomeArquivoSaida