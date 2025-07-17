#include <stdio.h>

//define a matriz quadrada
#define TAM 8
int main(){

    int M[TAM][TAM], i, j, elementos; 
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
        if (i < (TAM/2)){
            for (j = i; j < TAM-i; j++){
                media += M[i][j];
                elementos++;
            }
        }else {
             for (j = (TAM-i-1); j < TAM-i; j++){
                media += M[i][j];
                elementos++;
            }

        }
    }

    media /= elementos;
    printf("%lf\n", media);

    return 0;
}