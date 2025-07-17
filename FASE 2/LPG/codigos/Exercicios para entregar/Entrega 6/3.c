/*
Escreva um programa que aloca dinamicamente um vetor do tipo float e realiza a entrada de dados. Em seguida, o programa deve calcular a media dos valores do vetor e alocar dinamicamente um novo vetor contendo somente os valores maiores ou iguais a media. O processo pode ser feito usando malloc(), ou seja, fazendo a contagem, alocacao e copia dos valores. Outra alternativa consiste em usar realloc() para ir aumentando o espaco locado a medida que os valores vao sendo encontrados.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0, tam, j=0;
    float num, soma = 0, media;

    printf("Digite valores do tipo float, digite  qualquer letra para terminar: ");
    
    float *vetor = malloc(sizeof(float));

    while (scanf("%f", &num) == 1){
        vetor[i] = num;
        soma += num;
        i++;
        float *temp = realloc(vetor, sizeof(float)*(i+1)); //aloca mais memoria
        vetor = temp; // um ponteiro recepe outro ponteiro
    }
    tam = i;
    media = soma/(float)tam;
    
    float *maiores = malloc(sizeof(float));

    for(i = 0; i < tam; i++){
        if(vetor[i] >= media) {
            maiores[j] = vetor[i];
            j++;
            float *temp = realloc(maiores, sizeof(float)*(j+1));
            maiores = temp;
        }
    }

    printf("Maiores que %.2f: ", media);
    for (i = 0; i < j; i++){
        printf("%.2f ", maiores[i]);
    }
    printf("\n");
    free(vetor);
    free(maiores);
    

return 0;
}

