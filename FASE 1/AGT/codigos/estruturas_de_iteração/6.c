#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Elabore um algoritmo que imprima todos os primeiros N números primos existentes, sendo que N é um número natural fornecido pelo usuário.

int main() {     
    int num, contador = 0, numero = 2;
    scanf("%i", &num);
    
        while(contador < num){
            int primo = 1;

            for (int i = 2; i <= numero/2; i++){
                if (numero % i == 0){
                    primo = 0;
                    break;
                }
            }

            if (primo){
                printf("%i\n", numero);
                contador++;
            }

            numero++;
            
        }

    return 0;
}
    

