#include <stdio.h>
#include <stdlib.h>

int main (){
    int a, b, c;
    scanf("%d %d %d", &a , &b, &c);

    if ( (a > b+c) || (b > a + c) || (c > b+a)){
        printf("nao eh um triangulo!");
    } else {
        if ((a == b) && (b == c)){
            printf("eh um triangulo equilatero\n");
        } else if ((a == b) || (b == c) ) {
            printf ("eh um triangulo isoceles\n" );
        } else {
            printf ("eh um triangulo escaleno\n");
        }
    }

}
//%i = para inteiros mais preciso
//%d = para inteiros ;
//%f = para float;
// %lf = para double
// %c = para char