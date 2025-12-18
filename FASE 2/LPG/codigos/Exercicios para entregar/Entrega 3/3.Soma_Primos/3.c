/*Faca uma funcao que recebe um vetor e sua capacidade como parametros e retorna o somatorio dos numeros primos contidos no vetor. Recomenda-se utilizar a funcao de verificacao (se um numero e primo ou nao) ja implemetada. Prototipo:
int soma_primos(int v[], int n);*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int soma_primos(int v[], int n){
    int soma = 0;
    for (int i = 0; i < n; i++){
        if (primo(v[i])) soma += v[i];
    }
    return soma;
}

int main(){
    int tam, num;
    scanf("%i", &tam);
    int vetor[tam];

    for (int i = 0; i < tam; i++){
        scanf("%i", &num);
        vetor[i] = num;
    }
    
    printf("A soma dos primos no vetor eh: %i\n", soma_primos(vetor, tam));




return 0;
}


