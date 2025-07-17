--maior entre dois numero 
maior x y = if x > y then x else y

--eh triangulo
ehtriangulo a b c =  if a >= (b+c) then False else if b >= (a+c) then False else if c >= (a+b) then False else True 

ehtri a b c | a >= b+c = False
            | b >= a+c = False 
            | c >= a+b = False
            | otherwise = True
            

--tipo triangulo 
tipoTriangulo a b c | ehtri a b c == False = "Não eh um triangulo"
                    | a==b && b==c = "Equilatero"
                    | a==b || b==c || a==c = "Isoceles"
                    | a /= b && b /=c && a /= c = "Escaleno"

--Soma Pares
diminuiPar n = if rem n 2 == 0 then n else n-1
somaPar 0 = 0
somaPar 1 = 0
somaPar n = diminuiPar n + somaPar (n-2)

--Soma Pares 2
somaPares n = if rem n 2 == 0 then somaP n else somaP (n-1)
somaP 0 = 0
somaP n = n + somaP(n-2)

-- potencia
pot a 0 = 1
pot a b = a * pot a (b-1)

--fatorial
fat 0 = 1
fat m = m * fat (m-1)

-- Soma potencias 
somaPot2m m 0 = m
somaPot2m m n = m * pot 2 n + somaPot2m m (n-1)

--Numeros Primos 
divide m 1 = True
divide m n = if rem m n == 0 then False else divide m (n-1)
primo x = divide x (x-1)

--Serie pi
seriePi a = somaPi 1 1 a
somaPi a b c = if b <= c then a * 4/ b + somaPi (-1 *a) (b+2) c else 0






