#include <stdio.h>
#include <math.h>


double graus_em_rad(double graus){
    return (M_PI * graus)/180;
}

int main(){

    int n, i;
    double cosseno = 0;
    double x, graus;
    double termo;

    printf("Digite os graus:\n");
    scanf("%lf", &graus);
    printf("Digite o numero de termos:\n");
    scanf("%i", &n);

    termo = 1; // 1 termo
    x = graus_em_rad(graus); // x sera os graus em radianos

    for (i = 0; i <= 2*n; i+=2){
        cosseno += termo;
        termo *= x/(i+1)*x/(i+2)*(-1);
    }

    printf("Cosseno de %.2lf = %lf", graus, cosseno);
return 0;
}