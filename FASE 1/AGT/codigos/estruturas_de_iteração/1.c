#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Escrever um algoritmo que leia 20 valores para uma variável N e, para cada um deles, calcule a tabuada de 1 até N. Mostre a tabuada na forma: 
// 1 x N = N
// 2 x N = 2N
// 3 x N = 3N
// ......
// N x N = N2

#define TAM 20
int main() {
    int num, res, vetor [TAM];

    for (int i = 0; i < TAM; i++){
        scanf("%i", &vetor[i]);
        printf("tabuada de %i\n", vetor[i]);
        for (int j = 1; j <= vetor[i]; j++){
            res = j * vetor[i];
            printf("%i x %i = %i\n", j, vetor[i], res);
    }
    }
    return 0;

}