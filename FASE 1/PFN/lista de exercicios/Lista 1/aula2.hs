{-Fatorial-}
fat 0 = 1 -- FATORIAL DE 0 = 1
fat n = n*fat(n -1) 

--Potencia 
pot a 0 = 1
pot a b = a * pot a(b-1)

--Outra forma de potencia
potb b n =  if n == 0 then 1 else b*potb b(n-1)

--maior 
maior x y = if x > y then x else y
maior3 x y z = maior (maior x y) z

--MDC (Euclides)
mdc a b = if a==b then a else if a > b then mdc (a-b) b else mdc a (b-a)

--MDC melhorado
mdc2 a b | a==b = a
         | a>b = mdc2 (a-b) b
         | otherwise = mdc a (b-a)
         
--triangulo
ehtriangulo a b c =  if a >= b+c then False else if b >= (a+c) then False else if c >= (a+b) then False else True 

--triangulo melhorado 
ehtriangulo2 a b c |a > (b+c) = False  
                   |b > (a+c) = False
                   |c > (a+b) = False
                   |otherwise = True
                   
-- Tipo Triangulo 
tipotriangulo a b c |ehtriangulo2 a b c == False = "nao eh triangulo"
                    |a==b && b == c = "equilatero"
                    |a==b || b==c || c==a = "isosceles"
                    |a /= b && b /= a && a /= c = "escaleno"

-- Soma Pares
numeroPar n = if rem n 2 == 0 then True else False
diminuiPar n = if numeroPar n == False then n-1 else n
somaPar 0 = 0
somaPar 1 = 0
somaPar n = diminuiPar n + somaPar (n-2)

--Soma Potencia
somaPot2m m 0 = m
somaPot2m m n = m * pot 2 n + somaPot2m m (n-1)

-- Numero Primo
primo n  | n <= 1    = False
         | otherwise = not (any (\x -> n `rem` x == 0) [2..n-1])

