--[2*x|x<-[0..50]]

par n = rem n 2 == 0
--[x|x<-[0..5], par x] ou [x|x<-[0..5], rem x 2 == 0]

--[x+y|x<-[1,2,3], y<-[1,2]]

inc [] = []
inc (x:xs) = x+1:inc xs
inc' xs = [a+1|a<-xs]

--função take pega os primeiros numeros de uma lista ex. take 3 [1,2,3,4,5,6,7,8,9] = [1,2,3]

menor10 [] = []
menor10 (x:xs) = if x<10 then x:menor10 xs else menor10 xs
menores10 xs = [x|x<-xs, x<10]

uns = 1:uns
------------------------------------------
{-take 100 uns ira criar uma lista com 100 "1"

tabuada
[x*y|x<-[1..10], y<-[1..10]]

[(x,y,x*y)|x<-[1..10], y<-[1..10]] cria uma tripla
-}
