#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main() {
    double v, r;
    
    printf("Digite um Raio:\n");
    scanf("%lf", &r);
    v = (4.0/3.0) * 3.1415 * (pow(r, 3));
    printf("O volume = %lf \n", v);


}
