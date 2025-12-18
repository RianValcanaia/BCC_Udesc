//               Implemente as duas formas para calcular o valor aproximado de pi, conforme as
//               series a seguir. O numero de termos eh definido pelo usuario.
//               a) Serie de Gregory-Leibniz:

#include <stdio.h>

int main(){

    int k,a = 1,i,j = 1;
    double somatorio = 0;

    printf("Digite o numero de termos:\n");
    scanf("%i", &k);

    for (i = 1; i <= k; i++){
        somatorio += 4/(double)(a*j);
        printf("4/%i", j); 
        printf((i == k) ? " = " : (a == 1) ? " - " : " + " );
        a=a*-1;
        j += 2;
    }

    printf("%lf\n", somatorio);

return 0;
}