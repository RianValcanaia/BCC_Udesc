/*
Faca um programa que leia uma certa quantidade de inteiros que sao armazenados num vetor v. A quantidade deve ser definida pelo usuario, e o programa aloca espaco para v. O programa deve armazenar os valores positivos em um vetor vp e o valores negativos no vetor vn. Como as quantidades de valores positivos e negativos sao desconhecidas, o espaco para vp e vn deve ser alocado dinamicamente. Os vetores vp e vn nao devem conter zeros. Ao final, imprima os tres vetores. Pode ser feito com malloc() ou com realloc(
*/
#include <stdio.h>
#include <stdlib.h>


void imprime(int vetor[], int tam){
    for (int i = 0 ; i < tam; i++) (i==0)? printf("[%i, ", vetor[i]) : (i==tam-1)? printf("%i]\n", vetor[i]) : printf("%i, ", vetor[i]);
    
}

int main(){
    int i=0, tam, ivp=0, ivn = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);

    int *vetor = malloc (sizeof(int)*tam);

    while (i < tam){
        scanf("%i", &vetor[i]);
        i++;
    }
 
    int *vp = malloc(sizeof(int));
    int *vn = malloc(sizeof(int));


    for (i = 0; i < tam; i++){
        if (vetor[i]>0){
            vp[ivp] = vetor[i];
            ivp++;
            int *temp = realloc(vp, sizeof(int)*(ivp+1));   
        }else if (vetor[i] < 0){
            vn[ivn] = vetor[i];
            ivn++;
            int *temp = realloc(vn, sizeof(int)*(ivn+1));   
        }
    }

    puts("vetor original: ");
    imprime(vetor, tam);
    puts("vetor com numeros positivos: ");
    imprime(vp, ivp);
    puts("vetor com numeros negativos: ");
    imprime(vn, ivn);

    free(vetor);
    free(vp);
    free(vn);
return 0;
}

