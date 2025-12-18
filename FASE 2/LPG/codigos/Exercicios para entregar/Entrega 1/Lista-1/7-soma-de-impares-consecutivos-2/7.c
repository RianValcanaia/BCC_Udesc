//         Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre eles.

#include <stdio.h>

int somaImpares (int inicio, int fim);

int main(){

    int x, y, i, n;

    scanf("%i", &n);

    while (n--){
        scanf("%i %i", &x, &y);
        printf("%i\n\n", somaImpares(x,y));
    }

return 0;
}

int somaImpares (int a, int b){

    int temp, soma = 0, i;

    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }
    
    for (i = a+1; i < b; i++){
        if (i % 2 != 0)
            soma += i;    
    }

    return soma;
    
}