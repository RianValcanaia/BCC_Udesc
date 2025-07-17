/*
Escreva uma funcao que recebe um vetor float v e sua capacidade n, e retorne o endereco de um vetor alocado dinamicamente, cujo conteudo seja o mesmo de v, ou seja, a funcao retorna um clone do vetor v. Faca o programa principal com a entrada de dados (ou um vetor fixo), chame a funcao e mostre o vetor resultante na tela. Prototipo da funcao:

float *clone(float *v, int n );
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *clone( float *v, int n ){
    float *vet = malloc(sizeof(float) * n);
    for(int i = 0; i < n; i++){
        vet[i] = v[i];
    } 

    return vet;
}

int main(){
    int tam;
    printf("Digite o tamanho do vetor aleatorio: ");
    scanf("%i", &tam);
    float vetor[tam];
    
    srand(time(NULL));
    for (int i = 0; i < tam; i++) vetor[i] = ((float)random()/(float)RAND_MAX) *100.0;

    float *p = clone(vetor, tam);

    puts("Vetor original: ");
    for (int i = 0; i < tam; i++){
        printf("[%i] - %.2f\n", i,vetor[i]);
    }

    puts("\nvetor clonado: ");
    for (int i = 0; i < tam; i++){
        printf("[%i] - %.2f\n", i, p[i]);
    }

    free(p);

return 0;
}

