/*Escreva uma funcao que recebe dois vetores de mesma capacidade n e compara se os mesmos sao iguais, ou seja, se contem os mesmos valores e na mesma ordem. A funcaodeve ser booleana, ou seja, se forem iguais retorna 1, caso contrario retorna 0. Prototipo da funcao:
int compara(float a[], float b[], int n)*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compara(float a[], float b[], int n){
    for (int i = 0; i < n; i++){
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

int main(){
    float vetorA[10] = {1,2,3,121,451,213,6765,12,901,41};
    float vetorB[10] = {123,1,1245,1, 512,51,124214,631,513, 123};
    float vetorC[10] = {1.8,2.12,3.561,121.123,451.4124,213.612,6765.531,12.5,901.00,41.981239};
    float vetorD[10] = {1,2,3,121,451,213,6765,12,901,41};

    int tam = sizeof(vetorA)/sizeof(vetorA[0]);

    printf("%s\n", compara(vetorA, vetorB, tam)? "Vetores A e B iguais" : "Vetores A e B nao sao iguais" );
    printf("%s\n", compara(vetorA, vetorC, tam)? "Vetores A e C iguais" : "Vetores A e C nao sao iguais" );
    printf("%s\n", compara(vetorA, vetorD, tam)? "Vetores A e D iguais" : "Vetores A e D nao sao iguais" );


return 0;
}

