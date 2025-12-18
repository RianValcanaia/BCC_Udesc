#include <stdio.h>
#include <stdlib.h>

#define L 5
#define C 12

int main(){

    int i, j;
    double mediaQuente[L];
    double mediaFria[L];
    double mediaAnual[L] = {0};

    double matriz[L][C]={
    {120, 250.4, 240.2, 400, 200, 150, 130, 135.5, 250, 300, 580, 400},
    {280, 200, 210, 230.5, 200.2, 250.6, 230, 210.8, 240.44, 230, 210, 600},
    {500, 650, 400, 330, 300, 325, 310, 290, 350, 360, 350, 800},
    {1000, 1300, 1400, 1000, 700, 650, 500, 450, 500, 490, 510, 1200},
    {400, 450, 380, 320, 500, 780, 800, 900, 650, 500, 400, 350}};

    for (i = 0; i < L; i++){
        mediaQuente[i] = matriz[i][0] + matriz[i][1]+ matriz[i][11];
        mediaFria[i] = matriz[i][5] + matriz[i][6]+ matriz[i][7];
        for(j = 0;j < C; j++){
            mediaAnual[i] += matriz[i][j];
        }
    }

    for (i = 0; i < L;i++){
        printf("Casa %d\nMedia de consumo nos meses mais quentes: %.2lf\nMedia de consumo nos meses mais frios: %.2lf\nMedia de consumo anual: %.2lf\n\n", (i+1), (mediaQuente[i]/3), (mediaFria[i]/3), (mediaAnual[i]/C));
    }

return 0;
}