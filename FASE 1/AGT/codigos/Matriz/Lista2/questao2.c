#include <stdio.h>
#define TAM 6
#define MAX 100
int main(){

    int distancia = 0, inicio,i = 0;
    int rota[MAX];

    int MDistancia[TAM][TAM] = {{0,63,210,190,0,190}, 
                            {63,0,160,150,95,0},
                            {210,160,0,10,0,0},
                            {190,150,10,0,0,0},
                            {0,95,0,0,0,80}, 
                            {190,0,0,0,80,0}};

    printf("0 - Caceres;\n1 - BBugres;\n2 - Cuiaba;\n3 - VGrande;\n4 - Tangará;\n5 - PLacerda.\n");
    printf("Digite a rota que deseja fazer (digite -1 como ultimo numero para calcular a rota): ");

    while(1){
        scanf("%d", &rota[i]);
        if(rota[i] == -1){
            break;
        }
        i++;
    }    

    int tamanhoRota = i+1;
    
    for (i=1; i < tamanhoRota; i++){
        distancia += MDistancia[rota[i-1]][rota[i]];
    }
    printf("Distancia = %d\n", distancia);

    return 0;
}