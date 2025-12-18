//         Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre eles.

#include <stdio.h>


int main(){

    int x, y, i, soma = 0;

    scanf("%i %i", &x, &y);

    if (x < y){
        for (i = x; i <= y; i++){
            if (i % 2 != 0)
                soma += i;    
        }
    }
    else if (x > y){
        for (i = y; i <= x; i++){
            if (i % 2 != 0)
                soma += i;    
        }
    }
    
    printf("%i", soma);
    

return 0;
}