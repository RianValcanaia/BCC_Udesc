#include <stdio.h>

#define TAM 12
void printM (int matriz[TAM][TAM]){
    int i, j;
    printf("A Matriz respectiva:\n");
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int M[TAM][TAM] = { {0,1,1,1,1,1,1,1,1,1,1,0},
                        {0,0,1,1,1,1,1,1,1,1,0,0},
                        {0,0,0,1,1,1,1,1,1,0,0,0},
                        {0,0,0,0,1,1,1,1,0,0,0,0},
                        {0,0,0,0,0,1,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,1,1,0,0,0,0,0},
                        {0,0,0,0,1,1,1,1,0,0,0,0},
                        {0,0,0,1,1,1,1,1,1,0,0,0},
                        {0,0,1,1,1,1,1,1,1,1,0,0},
                        {0,1,1,1,1,1,1,1,1,1,1,0}};
    int i, j, maior = 0; 
    double media=0;

    // for (i = 0; i < TAM; i++){
    //     printf("Digite os numeros da linha %d\n", (i+1));
    //     for (j = 0; j < TAM; j++){
    //         scanf("%d", &M[i][j]);
    //     }
    // }
    
    printM(M);

    //teste print na tela
    // for (i = 0; i < TAM; i++) {
    //     if(i < TAM/2){
    //         for (j = 0 ; j < TAM; j++){
    //             if (j > i && j < TAM-i-1){
    //                 printf("*");
    //             }else{
    //                 printf("#");
    //             }
    //         }
    //         printf("\n");
    //     }else{
    //         for (j = 0 ; j < TAM; j++){
    //             if (j < i && j > TAM-i-1){
    //                 printf("*");
    //             }else{
    //                 printf("#");
    //             }
    //         }
    //         printf("\n");
    //     } 
    // }

    for (i = 0; i < TAM; i++) {
        if(i < TAM/2){
            for (j = 0 ; j < TAM; j++){
                if (j <= i || j >= TAM-i-1){
                    if (M[i][j] > maior){
                        maior = M[i][j];
                    }
                }
            }
        }else{
            for (j = 0 ; j < TAM; j++){
                if (j >= i || j <= TAM-i-1){
                    if (M[i][j] > maior){
                        maior = M[i][j];
                    }
                }
            }
        }    
    }
    
    printf("Maior: %d\n", maior);

    return 0;
}