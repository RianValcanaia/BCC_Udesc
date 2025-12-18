#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

int main() {
    int tam;
    // entrada
    int alvo;
    scanf("%i", &alvo);

    scanf("%i", &tam);
    int vetor[tam];
    for (int i = 0; i < tam; i++) {
        scanf("%i", &vetor[i]);
    }

    // busca binária
    int esquerda = 0;
    int direita = tam - 1;
    int res = -1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (vetor[meio] == alvo) {
            res = meio;
            break;
        } else if (vetor[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    // saída
    if (res != -1) {
        printf("%i\n", res);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}



