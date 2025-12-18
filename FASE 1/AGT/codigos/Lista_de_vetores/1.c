#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

int main() {
    int tam, menor, posmenor, aux;
    // entrada
    scanf("%i", &tam);
    int vetor[tam];

    for(int i = 0; i < tam; i++){
        scanf("%i", &vetor[i]);
    }

    for (int i = 0; i < tam; i++){
        menor = vetor[i];
        posmenor = i;
            for (int j = i; j < tam; j++){
                if (vetor[j] < menor){
                    menor = vetor[j];
                    posmenor = j;
                }
            }
        aux = vetor[i];
        vetor[i] = menor;
        vetor[posmenor] = aux;
    }
    for (int i = 0; i < tam; i++) {
        printf("%i, ", vetor[i]);
    }

    return 0;
}



