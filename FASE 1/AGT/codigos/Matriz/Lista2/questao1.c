#include <stdio.h>
#define TAM 6

int main(){

    int distancia = 0;
    int cidade[TAM][TAM] = {{0,63,210,190,0,190}, 
                            {63,0,160,150,95,0},
                            {210,160,0,10,0,0},
                            {190,150,10,0,0,0},
                            {0,95,0,0,0,80}, 
                            {190,0,0,0,80,0}};


    int vetor[5][2] = {{2,3},
                       {3,1},
                       {1,4},
                       {4,5},
                       {5,0}};

    for (int i = 0; i < 5; i++){
       distancia += cidade[vetor[i][0]][vetor[i][1]];
    }
    printf("Distancia: %d\n", distancia);


    return 0;
}