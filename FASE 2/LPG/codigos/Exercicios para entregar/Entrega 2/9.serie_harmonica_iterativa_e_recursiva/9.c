//       Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
//       recursiva) para determinar a soma S da série harmônica.
#include <stdio.h>

double harmonica (int n){
    if (n == 0){
        return 0;
    }else {
        return ((double)1/n) + harmonica (n-1);
    }
    
}

int main (){
    int n;
    double soma = 0;
    printf("Digite o valor de n:\n");
    scanf("%i", &n);
    
    for (int i = 1; i <= n; i++){
        soma += 1/(double)i;
    }
    
    printf("forma iterativa: %lf\n", soma);
    printf("forma recursiva: %lf\n", harmonica(n));
    
    
    
    return 0;
}