/*2) Escreva uma funcao que recebe um vetor v e um inteiro n. A funcao deve gerar o n termos de sequencia de Fibonacci dentro de v. Prototipo da funcao:
void fibonacci(int v[], int n);*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void fibonacci(int v[], int n){
    int a=0, b=1, temp;

    for (int i = 0; i < n; i++){
        temp = a;
        a = a+b;
        b = temp;
        v[i] = b;
    }
}

int main(){

    int tam;
    printf("Digite o a quantidade de termos da sequencia de fibonnanci:\n");
    scanf("%i", &tam);

    int vetor[tam];
    
    fibonacci(vetor,tam);

    for (int i = 0; i < tam; i++){
        printf("[%i] - %i\n", i+1, vetor[i]);
    }


return 0;
}

