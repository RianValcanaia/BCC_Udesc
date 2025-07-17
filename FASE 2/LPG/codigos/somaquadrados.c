// Faca um algoritmo para calcular a somatoria, a soma
// dos quadrados e a media dos N primeiros numeros
// naturais.
// – Exemplo: N=3
// • Soma: 1 + 2 + 3 = 6
// • Soma dos quadrados: 1² + 2² + 3² = 14
// • Média: Soma / N = 2

#include <stdio.h>
#include <math.h>

int main(){
    int n, soma = 0, quadrados = 0, cont=1;
    double media;
   
    printf("Digite o valor de N:\n");
    scanf(" %d", &n);
    
    while (cont <= n){
        soma += cont;
        quadrados += pow(cont, 2);
        cont++;

    }

    media = soma/(float)n;
    printf("\nSoma = %d\nQuadrados = %d\nMedia = %.2f\n", soma, quadrados, media);

    return 0;
}