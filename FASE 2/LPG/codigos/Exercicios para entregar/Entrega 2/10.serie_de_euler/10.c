//  Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
//  recursiva) para calcular o somatório que determina o valor da constante e:
#include <stdio.h>

double euler(int n, double soma) {
    if (n == 0) {
        return soma;
    } else {
        double fracao = 1.0;
        for (int i = 1; i <= n; i++) {
            fracao *= (double)1 / i;
        }
        return euler(n - 1, soma + fracao);
    }
}
    
int main (){
    int n;
    double soma = 1;
    printf("Digite o valor de n:\n");
    scanf("%i", &n);
    
    double fracao = 1;
    
    for (int i = 1; i <= n; i++){
        fracao *= (double)1/i;
        soma += fracao;
    }
    
    printf("forma iterativa: %lf\n", soma);
    printf("forma recursiva: %lf\n", euler(n,1.0));
    
    
    
    return 0;
}