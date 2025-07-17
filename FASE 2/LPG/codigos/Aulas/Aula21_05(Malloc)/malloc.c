#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int main(){
    float *p, x;
    p = malloc(sizeof(float));//aloca 8 bites em p
    scanf("%f", p);
    printf("%f\n", *p); //7.5
    x = *p;
    printf ("endereco de x:%d\n",  &x);
    printf("endereco alocado: %d\n", p);
    printf("%f\n", *p);
    free(p); //libera a memoria
    printf("%f", *p);
return 0;
}