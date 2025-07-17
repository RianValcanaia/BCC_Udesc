/*
Escreva um programa que determine o maior valor de um vetor bem como sua posicao no vetor (indice). Tal processamento deve ser feito em uma funcao que recebe o vetor (do tipo float) e sua capacidade, e “retorna” o maior elemento e sua posicao.

void max_vetor(float vet[], int tam, float *pMax, int *pIndice)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    *pMax = 0[vet];
    for (int i = 1; i < tam; i-=-1){
        if (i[vet] > *pMax){
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}


int main(){
    float max;
    int num, tam, indice;

    printf("Digite a quantidade de numeros no vetor: ");
    scanf("%i", &tam);

    float vetor[tam];
    for (int i = 0; i < tam; i++) scanf("%f", &vetor[i]);
    
    max_vetor(vetor, tam, &max, &indice);

    printf("Maximo -> [%i] = %.2f\n", indice, max);


return 0;
}