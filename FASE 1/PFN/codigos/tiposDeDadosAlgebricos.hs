import Data.List

-- Tipos de Dados Algébricos

--data Lista = Cons Int Lista|Nil deriving Show --Declado com Cons Int o tipo, que é um inteiro
--Cons = : = contrutor é um prefixo

--data ListaChar a = Cons a (ListaChar a)| Nil deriving Show

data ListaChar a = a :-: ListaChar a | Nil deriving Show -- não entendi como usar

data Semana = Dom|Seg|Ter|Qua|Qui|Sex|Sab deriving (Show,Eq,Ord)

data Booleano = V|F deriving Show

--data Dupla = Par Int Int deriving Show
data Dupla a b = Par a b deriving Show -- não entendi a diferença, construtor polimórfico

-- len Nil = 0
-- len (Cons x xs) = 1 + len xs
--
-- len' [] = 0
-- len' (x:xs) = 1 + len' xs
--
-- converte Nil = []
-- converte (Cons x xs) =  x: converte xs
{-Ex:
ghci> converte (Cons 1 (Cons 2 (Cons 3 Nil)))
[1,2,3]-}

exLista :: ListaChar Int
exLista = 1 :-: (3 :-: ( 7 :-: Nil))

{-
ex2Lista :: ListaChar Char
ex2Lista = Cons 'a' (Cons 'c' (Cons 'l' Nil))-}

neg V = F
neg F = V

proxCom Seg = Ter
proxCom Ter = Qua
proxCom Qua = Qui
proxCom Qui = Sex
proxCom d = Seg

primeiro (Par x y) = x
segundo (Par x y) = y

{- Ex: ghci>primeiro (Par 10 20)
10
ghci> segundo (Par 10 20)
20
-}

{-monada >>= e >> como usar? sortBy
sort ["Teste","Funcional", "Aula"]
--["Aula","Funcional","Teste"]-}

compara (x1,y1) (x2,y2) | y1 == y2 = EQ
                        | y1 < y2 = LT
                        | otherwise = GT

