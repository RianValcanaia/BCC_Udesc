//           Faça um programa que leia um inteiro n e determine a soma S da seguinte forma: 1 + 2 + 3
//           + 4 + ... + n. Escreva duas versões de funções: iterativa e recursiva.

#include <stdio.h>

int soma_recursiva(int n){
    if (n == 0){
        return 0;
    } else {
        return n + soma_recursiva(n-1);
    }
}

int main (){
    int n, soma = 0;
    
    scanf("%i", &n);
    
    for (int i = 1; i <= n; i++){
        soma += i;
    }
    printf("Forma iterativa: %i\n", soma);
    printf("Forma recursiva: %i\n", soma_recursiva(n));
    return 0;
    
}