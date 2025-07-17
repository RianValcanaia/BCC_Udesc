--Arvore Binária de pesquisa
data Lista a = Cons a (Lista a)|Nil deriving Show
--Cons 1 (Cons 2(Cons 3 Nil))

data Arvore a = No a (Arvore a)(Arvore a)|Folha deriving Show
--No 10 (No 7 (No 5 Folha Folha) (No 9 Folha Folha))(No 15 Folha (No 17 Folha Folha))

type Word' = String
data Arvore2 = No2 Word' [Int] (Arvore2)(Arvore2) | Folha2 deriving Show

pesquisa a Folha = False
pesquisa a (No x esq dir) = if a==x then True else if a<x then pesquisa a esq else pesquisa a dir

pesquisa' a Folha = False
pesquisa' a (No x esq dir) | a==x = True
                            | a<x = pesquisa' a esq
                            | otherwise = pesquisa' a dir

{-
Ex:
ghci> pesquisa 9 (No 10 (No 7 (No 5 Folha Folha) (No 9 Folha Folha))(No 15 Folha (No 17 Folha Folha)))
True
ghci> pesquisa 20 (No 10 (No 7 (No 5 Folha Folha) (No 9 Folha Folha))(No 15 Folha (No 17 Folha Folha)))
-}

ins a [] = [a]
ins a (x:xs) = if a < x then a:x:xs else x:ins a xs

ins' a Folha = No a Folha Folha
ins' a (No x esq dir) | a==x = No x esq dir
                      | a < x = No x (ins' a esq) dir
                      | otherwise = No x esq (ins' a dir)

{-
Ex:
ghci> ins' 9 (No 10 (No 7 Folha Folha) Folha)
No 10 (No 7 Folha (No 9 Folha Folha)) Folha
-}

percorrer Folha = []
percorrer (No x esq dir) = percorrer esq ++ [x] ++ percorrer dir
{-
Ex:
ghci> percorrer ( No 10 (No 7 Folha (No 9 Folha Folha)) Folha)
[7,9,10]
-}

--ins3 p l (No p' ins3 esq dir) | p == p' = No p' (in)
