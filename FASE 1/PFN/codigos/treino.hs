import Data.Char
data Arvore a = No a (Arvore a) (Arvore a) | Folha deriving Show
--Insere elemento na Arvore
ins a Folha = No a Folha Folha
ins a (No x esq dir) | a == x = (No x esq dir)
                     | a < x = (No x (ins a esq) dir)
                     | otherwise = (No x esq (ins a dir))
--listToTree
listToTree ls = listToTree' Folha ls
listToTree' arv [] = arv
listToTree' arv (x:xs) = listToTree' (ins x arv) xs
--treeToList



treeToList Folha = []
treeToList (No x esq dir) = (treeToList esq) ++ [x] ++ (treeToList dir)

maior [x] = x
maior (x:xs) = if x > maior xs then x else maior xs

maiorArv arvore = maior (treeToList (arvore))



maiorArv' (No a Folha Folha) = a
maiorArv' (No a esq dir) = maiorArv' dir


