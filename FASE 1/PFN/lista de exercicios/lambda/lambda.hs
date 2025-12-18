{- VALORES DE PRIMEIRA ORDEM

Funções Ordem Superior
-map
-flip (inverte a função, div 10 2 = 5, flip div 10 2 = 0 pois inverteu para div 2 10 = 0)
-filter
-fold(reduce)
-}
-- filter f [] = []
-- filter f (x:xs) = if f x then x : filter f xs else filter f xs

-- foldr f acc [] = acc
-- foldr f acc (x:xs) = f x (foldr f acc xs)
-- foldl f acc [] = acc
-- foldl f acc (x:xs) = foldl f (f acc x) xs


soma [] = []
soma (x:xs) = x+1:soma xs

dobra [] = []
dobra (x:xs) = x*2:dobra xs

inc x = x+1
dobro a = a*2

map' f [] = []
map' f (x:xs) = f x:map' f xs
{-
>map' inc [1,2,3,4]
>[2,3,4,5]

>map' dobro [1,2,3,4]
>[2,4,6,8]
-}

pares [] = []
pares (x:xs) = if rem x 2 == 0 then x:pares xs else pares xs

maiores10 [] = []
maiores10 (x:xs) = if x > 10 then x:maiores10 xs else maiores10 xs

par x = rem x 2 == 0

filter' p [] = []
filter' p (x:xs) = if p x then x:filter' p xs else filter' p xs
{-
>filter' (>10) [3,5,13,3,10,15]
>[13,15]

>filter' par [3,5,13,3,10,15]
[10]

>filter' (\x -> rem x 2 == 0) [2,4,3,1,5]
>[2,4]
-}

{-
------------------------------------------
 Lines
>lines "teste1\nteste2\nteste3\n"
>["teste1","teste2","teste3"]
------------------------------------------
PutStr
>putStr "teste1\nteste2\nteste3\n"
>teste1
>teste2
>teste3
------------------------------------------
Words
>words "Departamento de ciencia da computacao"
>["Departamento","de","ciencia","da","computacao"]
-}

a = 0
numLines (x:xs) = aux 1 (x:xs)
aux n [] = []
aux n (x:xs) = (n,x):aux (n+1) xs


allNumWords ((n,x):xs) = aux2 n (words x) ++ allNumWords xs

aux2 _ [] = []
aux2 n (x:xs) = (n,x): aux2 n xs







