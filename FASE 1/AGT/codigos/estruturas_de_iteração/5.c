#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Escrever um algoritmo que gera e escreve os 4 primeiros números perfeitos. Um número perfeito é aquele que é igual a soma dos seus divisores. (Ex.: 6 = 1+2+3; 28= 1+2+4+7+14 etc). 


int main() {     
    int soma, num = 2, contador = 0;
    
        while(contador < 4){
            soma = 1;

            for (int i = 2; i <= num/2; i++){
                if (num % i == 0){
                    soma += i;
                }
            }

            if (soma == num){
                printf("%i\n", num);
                contador++;
            }

            num++;
        }

    return 0;
    }
    

