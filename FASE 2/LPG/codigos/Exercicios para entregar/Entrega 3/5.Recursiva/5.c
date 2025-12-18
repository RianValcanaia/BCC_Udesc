/*Implemente a versao recursiva da funcao que faz a busca sequencial em um vetor. Prototipo da funcao:
int busca_seq_rec(int v[], int n, int chave)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int busca_seq_rec(int v[], int n, int chave){
    if (n==0) return 0;
    else if(v[n-1] == chave) return (n-1);
    else busca_seq_rec(v, (n-1), chave);
}

int main(){
    int tam, num, chave;
    puts("Digite o tamanho: ");
    scanf("%i", &tam);
    puts("Digite o vetor: ");
    int vetor[tam];

    for (int i = 0; i < tam; i++){
        scanf("%i", &num);
        vetor[i] = num;
    }

    puts("Digite a chave: ");

    scanf("%i", &chave);
    
    int indice = busca_seq_rec(vetor, tam, chave);

    (indice == 0)? printf("Nao encontrado\n") : printf ("chave encontrada na posicao: [%i]\n", indice);


return 0;
}
