#include <stdio.h>

int main(){
    int a = 0, b = 1, temp, cont = 2,n, soma=1;

    printf("Digite o numero de termos do fibonancci:\n");
    scanf("%d", &n);

    printf("1 - 1\n");

    while(cont <= n){

        temp = b;
        b= a+b;
        a= temp;
        printf("%d - %d\n", cont, b);
        cont++;
        soma += b;
    }

    printf("soma: %d\n", soma);


return 0;
}