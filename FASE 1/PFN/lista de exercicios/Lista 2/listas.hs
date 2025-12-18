-- Listas
maior [x] = x
maior (x:xs) = if x > maior xs then x else maior xs

--somatorio
somatorio [] = 0
somatorio (x:xs) = x + somatorio xs

-- tamanho
tam [] = 0
tam (x:xs) = 1 + tam xs

--fat
fat 0 =1
fat n = n * fat (n-1)

--tres primeiros
nprimeiros n [] = []
nprimeiros 0 _ = []
nprimeiros n (h:t) = h:nprimeiros (n-1) t

--n ocorrencias
nocorrencias a [] = 0
nocorrencias a (x:xs) = if a == x then 1 + nocorrencias a (xs) else nocorrencias a (xs)

--verifica igualdade
verificaigual [] [] = True
verificaigual [] _ = False
verificaigual _ [] = False
verificaigual (x:xs) (y:ys) = if x == y then verificaigual xs ys else False

--juntar [1,2,3] ++ [4,5] = [1,2,3,4,5]
concatena [] ys = ys
concatena (x:xs) ys = x:concatena xs ys

--potencia
pot n 0 = 1
pot n a = n * pot n (a-1)

-------------------------------- LISTA 2 --------------------------------

--1)pertence 3 [1, 4, 3, 2] => True
pertence n [] = False
pertence n (x:xs) = if n == x then True else pertence n (xs)

--2)intercessao [1, 3, 5, 7, 9] [2, 5, 3, 6, 9] => [3, 5, 9]
intercessao [] _ = []
intercessao (x:xs) (y:ys) = if pertence x (y:ys) then x:intercessao xs (y:ys) else intercessao xs (y:ys)

--3)inverso
inverso [] = []
inverso (x:xs) = inverso xs ++ [x] 

--4)nUltimos
nUltimos a [] = [] 
nUltimos a (x:xs) = inverso (nprimeiros a (inverso (x:xs))) 

--5)soma2
soma2 _ [] = []
soma2 (x:xs) (y:ys) = x+y: soma2 xs ys

--6)pot2 4
pot3 0 = []
pot3 n = pot 2 n:pot3 (n-1)
pot2 n = inverso (pot3 n)

--7)intercalacao
intercalacao [] (y:ys) = (y:ys)
intercalacao (x:xs) [] = (x:xs)
intercalacao (x:xs) (y:ys) = if x <= y then x:intercalacao xs (y:ys) else y:intercalacao (x:xs) ys

--8)menor
menor [x] = x
menor (x:xs) = if x < menor xs then x else menor xs

--9)removerElem
removerElem a [] = []
removerElem a (x:xs) = if a==x then xs else x:removerElem a xs

--10)ordenar
ordenar [] = []
ordenar xs = menor xs: ordenar (removerElem (menor xs) xs)

--11)ins 12 [6, 9, 10, 15, 20] => [6, 9, 10, 12, 15, 20]
ins a [] = []
ins a (x:xs) = if a < x then a:(x:xs) else x:ins a (xs)

--12)enesimo 3 [10, 20, 30, 40, 50] => 30
enesimo 1 (x:xs) = x
enesimo a (x:xs) = enesimo (a-1) xs

--13)repetir
repetir 0 n = []
repetir a n = n:repetir (a-1) n

--14)numString 126 => “126”
numString v = inverso (numStringaux v)
numStringaux::Int->[Char]
numStringaux 0 = []
numStringaux n = toEnum ((rem n 10) + 48):numStringaux (div n 10)

--15) stringNum “102” => 102
stringNum xs = stringNum' (inverso xs)
stringNum' [] = 0
stringNum' (x:xs) = (fromEnum x - 48) + 10 * stringNum' xs

--16)bin2int “1110” => 14
auxiliar [] = []
auxiliar (x:xs) = fromEnum x - 48: auxiliar xs
bin2int xs = bin2intAux (auxiliar xs)
bin2intAux [] = 0
bin2intAux (x:xs) = x * pot 2 (tam (xs)) + bin2intAux xs

--17)int2bin: 14 => “1110”
bin 0 = '0'
bin 1 = '1'
int2bin 0 = []
int2bin x = int2bin (div x 2) ++ [bin (rem x 2)]

--18) minusculas “AbCdeF” => “abcdef”
minusculas [] = []
minusculas (x:xs) = if fromEnum x < 91 then toEnum(fromEnum x + 32):minusculas xs else x:minusculas xs



-- [1,2,3,4] lista de numeros
-- ['a', 'b', 'c'] lista de caracteres = "abc"
--["programacao", "Funcional", "conputacao"]
--(toEnum _)::Char
