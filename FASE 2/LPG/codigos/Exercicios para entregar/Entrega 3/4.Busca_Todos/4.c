/*Escreva uma funcao que recebe um vetor v, sua capacidade n e uma chave de busca. A funcao tambem recebe um vetor que vai armazenar os indices em que a chave se encontra em v. A funcao deve fazer a busca de maneira sequencial e armazenar os indices em que a chave se encontra e preencher o resto do vetor com -1. Os vetores v e indices devem ter a mesma capacidade. Prototipo xda funcao
void busca_todos(int v[], int n, int chave, int indices[]);*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void busca_todos(int v[], int n, int chave, int indices[]){
    int j = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == chave){
            indices[j] = i;
            j++;
        }
    }
}

int main(){
    int tam, num, chave;
    scanf("%i", &tam);
    int vetor[tam];
    int indices[tam];
    memset(indices,-1,sizeof(indices));

    for (int i = 0; i < tam; i++){
        scanf("%i", &num);
        vetor[i] = num;
    }

    scanf("%i", &chave);

    busca_todos(vetor, tam, chave, indices);

    for (int i = 0; i < tam; i++) printf("%i ", indices[i]);


return 0;
}
