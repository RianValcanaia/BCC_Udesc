//     Faça um programa que mostre na tela os n primeiros termos da sequência de Fibonacci.
//     Por exemplo, dado n = 8, temos: 1, 1, 2, 3, 5, 8, 13 e 21. A determinação do n-ésimo termo
//     da sequência deve ser feita por uma função iterativa que tem o seguinte protótipo:
//                                      int fibo(int n);
#include <stdio.h>

int fibo(int n){
    int a = 0, b = 1, temp, cont=0;
    while (cont < n){
        temp = a;
        a = a + b;
        b = temp;
        printf("%i ", a); 
        cont++;
    }
}

int main(){
    int n, cont = 0;
    printf("Digite a quantidade de termos de Fibonacci\n");
    scanf("%i", &n);
    fibo(n);
    return 0;
}
