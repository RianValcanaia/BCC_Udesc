#include <stdio.h>

int main(){

    int k,a;
    double somatorio = 0;

    printf("Digite um valor de termos:\n");
    scanf("%i", &k);

    for (int i = 1; i <= k; i++){
        (i % 2 == 0) ? (a=-1) : (a = 1);
        printf("1/%i", i);  printf((i==k) ? " = " : (a==1) ? " - " : " + ");
        somatorio += 1/(double)(a*i);        
    }

    printf("%lf\n", somatorio);

return 0;
}