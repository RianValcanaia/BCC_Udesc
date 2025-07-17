#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Crie um programa que solicite liste todos os possíveis divisores de um número, de 1 até ele mesmo. Entende-se aqui que “divisor” é um número pelo qual pode-se dividir o valor desejado obtendo um quociente inteiro e resto zero. O número deverá ser solicitado ao usuário. Após a listagem dos divisores deste número o programa deverá pedir outro número até que o usuário digite o valor zero ou um valor negativo.

int main() {
    int num;
    
    
    while (1){
    scanf("%i", &num);
    if (num <= 0){
        return 0;
    }
    for (int i = 1; i <= num/2; i++){
        if (num % i == 0){
            printf("%i\n", i);
        }
    }
    }
return 0;
}