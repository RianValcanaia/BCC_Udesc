#include <stdio.h>

int main() {
    int tam, maximo = 0;
    scanf("%i", &tam);
    int vetor[tam];

    for (int i = 0; i < tam; i++) {
        scanf("%i", &vetor[i]);
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }

    // Crie o vetor de frequência e inicialize com zeros
    int frequencia[maximo + 1];
    for (int i = 0; i <= maximo; i++) {
        frequencia[i] = 0;
    }

    // Calcule as frequências
    for (int i = 0; i < tam; i++) {
        frequencia[vetor[i]]++;
    }

    // Exiba as frequências
    for (int i = 0; i <= maximo; i++) {
        if (frequencia[i] > 0) {
            printf("[%d]: %d\n", i, frequencia[i]);
        }
    }

    return 0;
}

