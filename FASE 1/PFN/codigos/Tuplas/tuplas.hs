
{-
Compreensão de Listas
[2*x | x <- [0..50]] -- números pares de 0 a 100
[x+y | x <- [1,2,3], y <- [1,2]] retorna: [2,3,3,4,4,5] somando X e Y
-}

---------------------
par n = rem n 2 == 0 -- devolve se um numero é par
{-
usar no GHCI:
ghci> [x| x <- [0..100], par x]
Isso devolvera uma lista com os números de 0 a 100 que, quando jogados na função 'par', devolvem true
-}

----------------------
inc [] = []
inc (h:t) = h+1:inc t -- incrementa cada elemento da lista em 1
incLista t = [a+1 | a <- t] -- faz a mesma coisa q a funcao inc

----------------------
-- n Primeiros (take)
{-
usar no GHCI:
ghci> take 3 [1,2,3,4,5,6] -- Devolve os 3 primeiros elemento da lista
SAÍDA: [1,2,3]
-}

----------------------
-- Numeros da lista q são menores que 10
{-
ENTRADA: menores10 [1,5,12,17,2,3]
SAÍDA: [1,5,2,3]
-}
menores10 [] = []
menores10 (h:t) = if h < 10 then h:menores10 t else menores10 t
menores10Lista t = [x | x <- t, x < 10] -- menores10 usando Compreensão de Listas
-- Explicação: Cria uma lista com elementos X tal que esses elementos, vindos de t, são menores que 10

----------------------
-- Criar lista infinita
uns = 1:uns -- Cria uma lista infinita de 1
{-
usar no GHCI:
ghci> take 100 uns
Devolve uma lista com cem elementos 1

usar no GHCI:
[1,1..] -- Cria uma lista infinita de 1 usando Compreensão de Listas
-}

----------------------
-- Tabuada
{-
ghci> [x*y | x <- [1..10], y <- [1..10]] -- Multiplica cada elemento da lista [1..10] por cada elemento da lista [1..10]
SAÍDA: [1,2,3,4,5,6,7,8,9,10,2,4,6,8,10,12,14,16,18,20,3,6,9,12,15,18,21,24,27,30,4,8,12,16,20,24,28,32,36,40,5,10,15,20,25,30,35,40,45,50,6,12,18,24,30,36,42,48,54,60,7,14,21,28,35,42,49,56,63,70,8,16,24,32,40,48,56,64,72,80,9,18,27,36,45,54,63,72,81,90,10,20,30,40,50,60,70,80,90,100]

ghci> [(x, y, x*y) | x <- [1..10], y <- [1..10]] -- Multiplica cada elemento da lista [1..10] por cada elemento da lista [1..10]
SAÍDA: [(1,1,1),(1,2,2),(1,3,3),(1,4,4),(1,5,5),(1,6,6),(1,7,7),(1,8,8),(1,9,9),(1,10,10),(2,1,2),(2,2,4),(2,3,6),(2,4,8),(2,5,10),(2,6,12),(2,7,14),(2,8,16),(2,9,18),(2,10,20),(3,1,3),(3,2,6),(3,3,9),(3,4,12),(3,5,15),(3,6,18),(3,7,21),(3,8,24),(3,9,27),(3,10,30),(4,1,4),(4,2,8),(4,3,12),(4,4,16),(4,5,20),(4,6,24),(4,7,28),(4,8,32),(4,9,36),(4,10,40),(5,1,5),(5,2,10),(5,3,15),(5,4,20),(5,5,25),(5,6,30),(5,7,35),(5,8,40),(5,9,45),(5,10,50),(6,1,6),(6,2,12),(6,3,18),(6,4,24),(6,5,30),(6,6,36),(6,7,42),(6,8,48),(6,9,54),(6,10,60),(7,1,7),(7,2,14),(7,3,21),(7,4,28),(7,5,35),(7,6,42),(7,7,49),(7,8,56),(7,9,63),(7,10,70),(8,1,8),(8,2,16),(8,3,24),(8,4,32),(8,5,40),(8,6,48),(8,7,56),(8,8,64),(8,9,72),(8,10,80),(9,1,9),(9,2,18),(9,3,27),(9,4,36),(9,5,45),(9,6,54),(9,7,63),(9,8,72),(9,9,81),(9,10,90),(10,1,10),(10,2,20),(10,3,30),(10,4,40),(10,5,50),(10,6,60),(10,7,70),(10,8,80),(10,9,90),(10,10,100)]

-}

----------------------
-- Elemento da tupla
{-
Separa os elementos de uma tupla
-}

primeiroTupla (x, y) = x; -- a mesma coisa que a função fts
segundoTupla (x, y) = y; -- a mesma coisa que a função snd

----------------------
-- Procura elemento da tupla
{-
Recebe uma lista de tuplas associando um número à um número.
Recebe um número e devolve o nome associado ao número.

ghci> procura 20 [(10, "Rian"), (20, "Andre"), (30, "Lucas")]
SAÍDA: "Andre"
-}

procura c [] = ""
procura c ((d, n): t) = if c == d then n else procura c t

-- Mesma função usando fst e snd
procura2 c [] = ""
procura2 c (h:t) = if fst h == c then snd h else procura2 c t

----------------------
-- Segundos
{-
Recebe uma lista de tuplas.
Devolve o segundo elmento de cada tupla.

ghci> segundos 20 [(10, "Rian"), (20, "Andre"), (30, "Lucas")]
SAÍDA: ["Rian","Andre","Lucas"]
-}

segundos [] = []
segundos ((f, s):t) = s:segundos t

-- Mesma função usando fst e snd
segundos2 [] = []
segundos2 (h:t) = snd h:segundos2 t

----------------------
-- Agrupar em duplas
{-
Recebe duas listas.
Agrupa cada elemento da primeira lista com o correspondente elemento da segunda lista.

ghci> agrupar [1,2,3,4] "abcdef"
SAÍDA: [(1,'a'),(2,'b'),(3,'c'),(4,'d')]

ghci> agrupar [1..] ["Lucas", "Cu", "Andre", "Marquinhos"]
SAÍDA: [(1,"Lucas"),(2,"Cu"),(3,"Andre"),(4,"Marquinhos")]
-}

agruparDupla [] ys = []
agruparDupla xs [] = []
agruparDupla (x:xs) (y:ys) = (x,y):agruparDupla xs ys

----------------------
-- Elemento da tripla
{-
Devolve n elemento da tripla.
-}

primeiroTripla (a, b,c ) = a;
segundoTripla (a, b, c) = b;
terceiroTripla (a, b, c) = c;

----------------------
-- Agrupar em tripla
{-
Recebe tres listas.
Agrupa cada elemento da primeira lista com o correspondente elemento da segunda e da terceira lista.

ghci> agruparTripla [1,2,3,4] "abcdef" [9, 8, 7, 6, 5, 4, 2, 1]
SAÍDA: [(1,'a',9),(2,'b',8),(3,'c',7),(4,'d',6)]
-}

agruparTripla [] ys zs = []
agruparTripla xs [] zs = []
agruparTripla xs ys [] = []
agruparTripla (x:xs) (y:ys) (z:zs) = (x,y,z):agruparTripla xs ys zs

-----------------------
--Inverter
--recebe: inverter [(1,2),(3,4),(5,6)]
--devolve: [(2,1),(4,3),(6,5)]

inverter [] = []
inverter ((x,y):xs) = (y,x): inverter xs

------------------------
--Rel menor
--relMenor [(1,2),(3,10),(2,7)]
--True
--relMenor [(10,12),(12,9),(5,7)]
--False
relMenor [] = True
relMenor ((x,y): xs) = if x > y then False else relMenor xs

-------------------------
--tamanhos
tamanhos [] = []
tamanhos (x:xs) = (x,length x): tamanhos xs

-------------------------
--soma
--soma o primeiro elemento de cada lista e o segundo de cada lista
soma xs = (somaAux1 xs, somaAux2 xs)
somaAux1 [] = 0
somaAux1 ((x,y):ys) = x + somaAux1 ys
somaAux2 [] = 0
somaAux2 ((x,y):ys) = y + somaAux2 ys

------------------------
--soma
soma2 [] = (0,0)
soma2 ((x,y):xs) = (x+fst(soma2 xs), y+snd(soma2 xs))

------------------------
soma3 [] = (0,0)
soma3 ((x,y):xs) = (x + s1, y + s2)
    where
        (s1,s2) = soma xs

------------------------
soma4 [] = (0,0)
soma4 ((x,y):xs) = let (s1,s2) = soma xs in (x+s1,y+s2)
