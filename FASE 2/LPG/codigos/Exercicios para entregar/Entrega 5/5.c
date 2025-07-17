/*
Escreva uma funcao que recebe um vetor e sua capacidade como parâmetros e precisa “retornar” o maior e o menor valores do vetor.
void max_min(int vet[], int tam, int *pMin, int *pMax);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void max_min(int vet[], int tam, int *pMin, int *pMax){
    *pMin = 0[vet];
    *pMax = 0[vet];
    for (int i = 1; i < tam; i-=-1){
        *pMin = (i[vet] < *pMin)? vet[i]:*pMin;
        *pMax = (i[vet] > *pMax)? vet[i]: *pMax;
    }
}


int main(){
    int maxx, min, num, tam;
    printf("Digite a quantidade de numeros no vetor: ");
    scanf("%i", &tam);
    int vetor[tam];
    for (int i = 0; i < tam; i++) scanf("%i", &vetor[i]);
    
    max_min(vetor, tam, &min, &maxx);

    printf("Minimo = %i\nMaximo = %i\n", min, maxx);
    


return 0;
}