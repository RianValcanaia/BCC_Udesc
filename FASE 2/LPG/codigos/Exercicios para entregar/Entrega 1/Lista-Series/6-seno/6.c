#include <stdio.h>
#include <math.h>


double graus_em_rad(double graus){
    return (M_PI * graus)/180;
}

int main(){

    int n, i;
    double seno = 0;
    double x, graus;
    double termo;

    printf("Digite os graus:\n");
    scanf("%lf", &graus);
    printf("Digite o numero de termos:\n");
    scanf("%i", &n);

    termo = graus_em_rad(graus); // 1 termo
    x = termo;  // x sera os graus em radianos

    for (i = 1; i <= 2*n; i+=2){
        seno += termo;
        termo *= x/(i+1)*x/(i+2)*(-1);
    }

    printf("Seno de %.2lf = %lf", graus, seno);
return 0;
}