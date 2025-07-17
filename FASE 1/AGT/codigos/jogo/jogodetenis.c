#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){
    int c, t;

    printf("O tempo está Seco ou Chuvoso? (1 para seco e 2 para chuvoso)\n");
    scanf("%d", &c);
    printf("O tempo está frio ou quente? (1 para frio e 2 para quente)\n");
    scanf("%d", &t);

    if ( (c == 1) && ( t == 1)){
        printf("Otimo dia para jogar!");
    } else if ( (c == 1) && (t == 2)){
        printf("Pessimo dia para jogar!");
    } else if ( (c == 2) && (t == 1)){
        printf("Pessimo dia para jogar!");
    } else if ( (c == 2) && ( t == 2)){
        printf("Otimo dia para jogar!");
    }

}