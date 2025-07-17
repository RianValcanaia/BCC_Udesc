//      Leia N valores Inteiros. A seguir mostre quantos valores digitados foram pares, quantos valores
//      digitados foram ímpares, quantos valores digitados foram positivos e quantos valores digitados
//      foram negativos


#include <stdio.h>

int main(){

    int n, par = 0, impar = 0, positivo = 0, negativo = 0, num;

    scanf("%i", &n);

    while (n > 0){
        scanf(" %i", &num);

        if (num > 0){
            positivo++;
            if(num % 2 == 0)
                par++;
            else
                impar++;
        
        }
        if (num < 0){
            negativo++;
            if(num % 2 == 0)
                par++;
            else
                impar++;
        
        }
        if (num == 0) 
            par++;

        n--;
    }

    printf("%i valor(es) par(es)\n%i valor(es) impar(es)\n%i valor(es) positivo(s)\n%i valor(es) negativo(s)", par, impar, positivo, negativo);

return 0;
}