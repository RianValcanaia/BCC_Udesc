-- eh Triangulo
ehTriangulo a b c | a >= b+c = False
                  | b >= a+c = False 
                  | c >= a+b = False
                  | otherwise = True
                  
-- Tipo Triangulo 
tipoTriangulo a b c | a==b && b==c = "equilatero"
                    | a==b || b==c || a==c = "isoceles"
                    | a /= b && b /=c && a /= c = "escaleno"

-- Triangulo                
triangulo a b c | ehTriangulo a b c == False = "nao eh um triangulo"     
                | a==b && b==c = "equilatero"
                | a==b || b==c || a==c = "isoceles"
                | a /= b && b /=c && a /= c = "escaleno"

-- Soma Pares 
somaPares n = if rem n 2 == 0 then somaP n else somaP (n-1)
somaP 0 = 0
somaP n = n + somaP(n-2)

-- potencia
pot a 0 = 1
pot a b = a * pot a (b-1)

-- Soma potencias 
somaPot2m m 0 = m
somaPot2m m n = m * pot 2 n + somaPot2m m (n-1)

--Numeros Primos 
divide m 1 = True
divide m n = if rem m n == 0 then False else divide m (n-1)
primo x = divide x (x-1)

--Serie pi
seriePI a = somaPi 1 1 a
somaPi a b c = if b <= c then a * 4/ b + somaPi (-1 *a) (b+2) c else 0



