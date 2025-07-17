#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tam, aux;
    // entrada
    scanf("%i", &tam);
    int vetor[tam];

    for(int i = 0; i < tam; i++){
        scanf("%i", &vetor[i]);
    }

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        printf("%i, ", vetor[i]);
    }

    return 0;
}



