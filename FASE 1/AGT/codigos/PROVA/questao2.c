#include <stdio.h>
#include <stdlib.h>

#define L 5
#define C 12

void gastoMaior(double frio, int quente){
    if(frio>quente){
        printf("Gasto maior no periodo mais frio\n");
    }else{
        printf("Gasto maior no periodo mais quente\n");
    }
}

void selectionSort(double mediaMensal[], int referenciaMes[]){
    double aux, menor;
    int i, j, posMenor;
    for (int i = 0; i < C; i++){
        menor = mediaMensal[i];
        posMenor = i;
            for (int j = i; j < C; j++){
                if (mediaMensal[j] > menor){
                    menor = mediaMensal[j];
                    posMenor = j;
                }
            }
        aux = mediaMensal[i];
        mediaMensal[i] = menor;
        mediaMensal[posMenor] = aux;
        
        //Vetor referencia
        aux = referenciaMes[i];
        referenciaMes[i] = referenciaMes[posMenor];
        referenciaMes[posMenor] = aux;
    }
}

void printMatriz(double matriz[], int referencia[]){
    int i;
    for (i = 0; i < C; i++){
        printf("%d\t%.2lf\n", referencia[i], (matriz[i]/L));
    }
}

int main(){

    int i, j;
    double mediaQuente[L];
    double mediaFria[L];
    double mediaMensal[C] = {0};
    int referenciaMes[C];

    double matriz[L][C]={
    {120, 250.4, 240.2, 400, 200, 150, 130, 135.5, 250, 300, 580, 400},
    {280, 200, 210, 230.5, 200.2, 250.6, 230, 210.8, 240.44, 230, 210, 600},
    {500, 650, 400, 330, 300, 325, 310, 290, 350, 360, 350, 800},
    {1000, 1300, 1400, 1000, 700, 650, 500, 450, 500, 490, 510, 1200},
    {400, 450, 380, 320, 500, 780, 800, 900, 650, 500, 400, 350}};

    for (i = 0; i < L; i++){
        mediaQuente[i] = matriz[i][0] + matriz[i][1]+ matriz[i][11];
        mediaFria[i] = matriz[i][5] + matriz[i][6]+ matriz[i][7];
    }

    for (i = 0; i < C;i++){
        referenciaMes[i] = i;
        for(j = 0;j < L; j++){
            mediaMensal[i] += matriz[j][i];
        }
    }
    
    for (i = 0; i < L;i++){
        printf("Casa %d\n", (i+1));
        gastoMaior(mediaFria[i], mediaQuente[i]);
    }

    selectionSort(mediaMensal, referenciaMes);
    printf("\nOrdenacao da media do condominio do maior gasto para o menor\nMes\tGasto\n");
    printMatriz(mediaMensal, referenciaMes);

return 0;
}