/*
Escreva uma funcao que troca os valores entre duas variaveis do tipo float. Faca um programa que leia duas variaveis e mostre seus valores na tela. Em seguida, troque os valores (usando a funcao) e mostre novamente os valores.
void troca_valor(float *x, float *y);
*/

#include <stdio.h>
#include <stdlib.h>

void troca_valor(float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    float a, b;
    printf("Digite dois numeros a e b respectivamente: ");
    scanf("%f %f", &a, &b);

    printf ("a = %f\nb = %f\n", a,b);
    troca_valor(&a, &b);
    puts("Trocados");
    printf ("a = %f\nb = %f\n", a,b);

return 0;
}