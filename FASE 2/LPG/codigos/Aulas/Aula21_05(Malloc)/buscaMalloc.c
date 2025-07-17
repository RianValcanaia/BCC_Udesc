#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int *busca (int v[], int n, int c){
    int i, cont = 0;
    for (i=0;i<n;i++){
        if (v[i]==c)cont++;
    }
    int *p = malloc(sizeof(int)*(cont+1));
    int j=0;
    for (i = 0; i < n; i++){
        if (v[i]==c){
            p[j]=i;
            j++;
        }
    }
    p[j]=-1;
    return p;
}

int *busca_v2(int v[], int n, int c){
    int i, cont = 0;
    int *p = malloc (sizeof(int));
    for (i = 0; i < n; i++){
        if (v[i] == c){
            p[cont] = i;
            cont++;
            p = realloc (p,sizeof(int)*(cont+1)); 
        }
    }
    p[cont]= -1;
    return p;
}

int main(){
    int vetor[] = {1,2,3,4,5,1,3,61,51,2,4,56};
    int k = sizeof(vetor)/sizeof(vetor[0]);

    int chave;
    printf("Digite o valor a ser buscado\n");
    scanf("%i", &chave);

    int *id = busca_v2(vetor, k, chave);
    if (id[0] == -1){
        printf("Nao encontrado\n");
    }else{
        printf("Encontrado nos indices: ");
        for (int i = 0; id[i] != -1; i++) printf("%d ", id[i]);
        
    }
    free(id);





return 0;
}