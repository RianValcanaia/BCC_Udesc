#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <math.h>

int raizes(int a, int b, int c, float *x1, float *x2){
    int raizando = b*b -4*a*c;
    double raiz;

    if(raizando < 0)return 0;
    else{
    raiz = sqrt(raizando);
    *x1 = (-b + raiz)/(2*a);
    *x1 = (-b - raiz)/(2*a); 
    return 1;
    }

}


int main(){
    int a, b,c;
    float x1, x2;

    scanf("%i %i %i", &a, &b, &c);

    if(raizes(a,b,c, &x1, &x2)) printf("x1 = %f\nx2 = %f", x1, x2);
    else printf("Nao existe raizes reais\n");


    // int t, hora, minutos, segundos;

    // printf("Digite o tempo em segundos:\n");
    // scanf("%i", &t);

    // converte(t, &hora, &minutos, &segundos);

    // pintf("")


return 0;
}
