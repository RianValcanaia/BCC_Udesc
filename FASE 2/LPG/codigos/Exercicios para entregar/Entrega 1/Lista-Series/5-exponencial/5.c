
// Implemente a serie de Taylor para calcular a funcao exponencial. O algoritmo deve solicitar como entrada o valor de x e quantidade de termos da seri.

#include <stdio.h>

int main(){

    int k, i, j;
    double x, somatorio = 0, fracao;

    printf("Digite o numero que sera o exponencial:\n");
    scanf("%lf", &x );
    printf("Digite o numero de termos da serie:\n");
    scanf("%i", &k);
    
    for (i=0; i <= k; i++){
        fracao = 1;
        for (j = 1; j <= i; j++){
            fracao *= x/j;
        }
        somatorio += fracao;
    }

   printf("e^%.2f = %lf (precisao de %i termos)", x, somatorio, k);

return 0;
}