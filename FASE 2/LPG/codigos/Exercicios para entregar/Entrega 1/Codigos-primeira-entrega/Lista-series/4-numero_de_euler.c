#include <stdio.h>

int main(){
    int k, i, j;
    long long double euler = 1, fracao;

    printf("Digite o numero de termos:\n");
    scanf("%i", &k);

    for (i = 1; i <= k; i++){
        fracao = 1;
        for (j=1; j<=i; j++){
            fracao *= (double)1/j;
        }
        euler += fracao;
    }

    printf("e com precisao de %i termo(s) eh: %lf\n", k, euler);

return 0;
}
