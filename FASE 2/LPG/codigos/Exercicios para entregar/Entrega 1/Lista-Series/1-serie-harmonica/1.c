//               Faça um algoritmo que mostre na tela os k termos da série harmônica e, ao final,
//               mostre o somatório dos termos. O número de termos da série é definido pelo
//               usuário.

#include <stdio.h>

int main(){

    int k;
    double somatorio = 0;

    printf("Digite um valor de termos da Serie harmonica:\n");
    scanf("%i", &k);

    for (int i = 1; i <= k; i++){
        printf("1/%i", i);  printf((i<k) ? " + " : " = ");
        somatorio += 1/(double)i;
    }

    printf("%lf\n", somatorio);

return 0;
}