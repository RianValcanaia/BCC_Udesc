#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void printMatriz (int M[][TAM]){
    for (int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%d\t", M[i][j]);
        }
    printf("\n");
    }
} 

int menorLinha (int M[][TAM], int linha, int coluna){
    int menor = M[linha][coluna], menorL = linha;
    for (int i = linha; i < TAM; i++){       
        for(int j = coluna; j < TAM; j++){
            if (M[i][j] < menor){
                menor = M[i][j];
                menorL = i;
            }
        }
    }
    return menorL;
}

int menorColuna (int M[][TAM], int linha, int coluna){
    int menor = M[linha][coluna], menorC = coluna;
    for (int i = linha; i < TAM; i++){       
        for(int j = coluna; j < TAM; j++){
            if (M[i][j] < menor){
                menor = M[i][j];
                menorC = j;
            }
        }
    }
    return menorC;
}

void troca (int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void sortMatriz (int M[][TAM]){
    int menorL, menorC;
    for (int i = 0; i < TAM; i++){       
        for(int j = 0; j < TAM; j++){
            menorL = menorLinha(M, i, j);
            menorC = menorColuna (M, i, j);
            troca(&M[i][j], &M[menorL][menorC]);
        }
    }
}

int main(){
    int M[TAM][TAM] = {25,24,23,22,21,20,19,28,17,16,15,14,200,12,2,13,26,9,8,7,100,5,4,29,5};
    printf("Matriz Original\n");
    printMatriz (M);
    sortMatriz(M);
    printf("Matriz Ordenada\n");
    printMatriz(M);
return 0;
}