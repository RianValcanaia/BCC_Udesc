#include <stdio.h>

//define a matriz quadrada
#define TAM 12
int main(){

    int M[TAM][TAM], i, j, menor = 1000000; 
    double media=0;

    for (i = 0; i < TAM; i++){
        printf("Digite os numeros da linha %d\n", (i+1));
        for (j = 0; j < TAM; j++){
            scanf("%d", &M[i][j]);
        }
    }

    printf("A Matriz respectiva:\n");
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < TAM; i++){
        for (j=0; j < TAM-i; j++){
            if (M[i][j] < menor){
                menor = M[i][j];
            }
        }
    }

    printf("%d\n", menor);

    return 0;
}