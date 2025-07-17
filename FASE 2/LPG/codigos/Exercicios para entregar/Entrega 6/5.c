/*
Escreva uma funcao que realiza a uniao entre dois conjuntos de inteiros contidos nos vetores v1 e v2. A funcao recebe os vetores e suas respectivas capacidades (n1 e n2) como parametros de entrada e retorna o endereco do vetor alocado (contendo a uniao entre v1 e v2). Alem disso, ha um parametro passado por referencia (ponteiro p3), que serve para “retornar” a capacidade do vetor gerado. Faca o programa principal invocando a funcao (a estrutura do programa e semelhante ao exemplo dado em aula - intersecao). Prototipo da funcao:
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );
*/
#include <stdio.h>
#include <stdlib.h>


int buscaSeq(int vetor[], int tam, int chave){
    for (int i = 0; i < tam; i++){
        if (vetor[i] == chave) return 1;
    }
    return 0;
}

int *uniao(int *v1, int n1, int *v2, int n2, int *p3) {
    int *uniao = malloc(sizeof(int) * (n1+n2)); 

    for (int i = 0; i < n1; i++) {
        uniao[i] = v1[i];
    }
    *p3 = n1; 
    for (int i = 0; i < n2; i++) {
        if (!buscaSeq(uniao, *p3, v2[i])) {
            uniao[*p3] = v2[i];
            (*p3)++; 
        }
    }
    int *temp = realloc (uniao, sizeof(int)*(*p3));
    uniao = temp;
    return uniao;
}

void imprime(int vetor[], int tam){
    for (int i = 0 ; i < tam; i++) (i==0)? printf("[%i, ", vetor[i]) : (i==tam-1)? printf("%i]\n", vetor[i]) : printf("%i, ", vetor[i]);
    
}

int main(){
    int i=0, tamA, tamB, tamUniao, *vetorA, *vetorB, *uni;

    puts("Digite o tamanho do primeiro vetor: ");
    scanf("%i", &tamA);
    vetorA = malloc (sizeof(int)*tamA);
    puts("Digite o primeiro vetor: ");
    while (i < tamA){
        scanf("%i", &vetorA[i]);
        i++;
    }
    i=0;
    puts("Digite o tamanho do segundo vetor: ");
    scanf("%i", &tamB);
    vetorB = malloc (sizeof(int)*tamB);
    puts("Digite o segundo vetor: ");
    while (i < tamB){
        scanf("%i", &vetorB[i]);
        i++;
    }

    uni = uniao(vetorA, tamA, vetorB, tamB, &tamUniao);

    puts("Uniao entre os conjuntos: ");
    imprime(uni, tamUniao);

    free(uni);
    free(vetorA);
    free(vetorB);

return 0;
}

