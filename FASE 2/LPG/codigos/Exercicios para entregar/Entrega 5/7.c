/*
Faca um programa que determine o menor valor de uma matriz 3x4, bem como suas coordenadas (linha e coluna). Tal processamento deve ser feito por uma funcao que recebe a matriz e “retorna” o menor elemento e suas coordenadas (i e j).

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (mat[i][j] < *pMin){
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
        }      
    }
}


int main(){
    float matriz[3][4];
    float min;
    int i, j;

    for (i = 0; i < 3;i++){
        for (j=0; j<4;j++){
            matriz[i][j] = ((float)rand() / (float)RAND_MAX) * 100.0;
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
    }

    min_matriz(matriz, &min, &i, &j);
    printf("Menor -> [%i][%i] = %f", i, j, min);


return 0;
}