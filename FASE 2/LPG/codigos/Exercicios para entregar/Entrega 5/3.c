/*
Faca uma Funcao que calcula o perimetro e a area de um circulo, dado o raio. 
void calcula_circulo(float raio, float *pPerimetro, float *pArea);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pArea = M_PI * (raio*raio);
    *pPerimetro = M_PI * 2 * raio;
}


int main(){
    float raio, perimetro, area;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    calcula_circulo(raio, &perimetro, &area);
    printf("perimetro = %.2f\narea = %.2f\n", perimetro, area);

return 0;
}