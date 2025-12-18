#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10
int main() {

    int num, i, distancia, distanciaMinima, numeroMaisProximo, vetor[TAM];
    int posicao[TAM], numeros[TAM], contador = 0;

    scanf("%i", &num);

    //entrada vetor
    for (i=0; i < TAM; i++){
        scanf("%i", &vetor[i]);
    }

    distanciaMinima = 10e5;

    for (i=0; i < TAM; i++){
        distancia = fabs(num - vetor[i]);
        if (distancia < distanciaMinima){
            distanciaMinima = distancia;
            numeros[0] = vetor[i];
            posicao[0] = i;
            contador = 1;
        } else if (distancia == distanciaMinima){
            numeros[contador] = vetor[i];
            posicao[contador] = i;
            contador++;
        }
    }

    for (i=0; i < contador; i++){
        printf("%i \npos %i\n", numeros[i], posicao[i]);
    }

}
