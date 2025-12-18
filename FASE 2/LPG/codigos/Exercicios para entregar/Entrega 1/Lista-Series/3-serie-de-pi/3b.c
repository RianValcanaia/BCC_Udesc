//               Implemente as duas formas para calcular o valor aproximado de pi, conforme as
//               series a seguir. O numero de termos eh definido pelo usuario.
//               b) Serie de Nilakantha:

#include <stdio.h>

int main(){

    int k,a = 1,i,j = 2;
    double somatorio = 3;

    printf("Digite o numero de termos:\n");
    scanf("%i", &k);

    printf("3 + ");
    for (i = 1; i <= k; i++){
        somatorio += 4/(double)(a * j * (j+1) * (j+2));
        printf("4/(%i*%i*%i) ", j, j+1, j+2); 
        printf((i == k) ? " = " : (a == 1) ? " - " : " + " );
        a=a*-1;
        j += 2;
    }

    printf("%lf\n", somatorio);

return 0;
}