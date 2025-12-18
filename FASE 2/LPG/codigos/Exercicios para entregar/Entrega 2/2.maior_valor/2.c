//          Faca uma funcao que recebe tres valores inteiros e retorna o maior valor. E preciso
//          considerar que podem haver dois (ou mesmo os tres) parametros iguais como sendo o
//          maior valor. Por exemplo, os parametros poderiam ser 5, 8 e 8. Neste caso, a funcao deve
//          retornar 8


#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b, int c){
    if (a >= b && a >=c)
        return a;
    else if (b>=c && b>=a)
        return b;
    else if (c>=a && c>=b)
        return c;
}


int main(){

    int a, b, c;
    printf("Digite tres valores inteiros\n");
    scanf("%i %i %i", &a, &b, &c);

    printf("%i", maior(a,b,c));

return 0;
}