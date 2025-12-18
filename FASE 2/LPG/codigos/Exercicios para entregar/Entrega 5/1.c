/*
Faca uma funcao que recebe dois nnmeros, a e b. A funcao deve incrementar a e decrementar b.
void inc_dec (int *a, int *b);
*/
#include <stdio.h>
#include <stdlib.h>

void inc_dec (int *a, int *b){
    (*a)++;
    (*b)--;
}

int main(){
    int a, b;

    printf("Digite dois numeros a e b respectivamente: ");
    scanf("%i %i", &a, &b);

    inc_dec(&a, &b);

    printf("a = %i\nb = %i\n", a, b);



return 0;
}