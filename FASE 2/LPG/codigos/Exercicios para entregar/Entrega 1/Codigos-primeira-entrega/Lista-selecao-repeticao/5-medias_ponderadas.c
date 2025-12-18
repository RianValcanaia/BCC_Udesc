//           Leia 1 valor inteiro N, que representa o número de casos de teste que vem a seguir. Cada caso de
//           teste consiste de 3 valores reais, cada um deles com uma casa decimal. Apresente a média
//           ponderada para cada um destes conjuntos de 3 valores, sendo que o primeiro valor tem peso 2, o
//           segundo valor tem peso 3 e o terceiro valor tem peso 5

#include <stdio.h>

int main(){

    int n, tt;
    float num, soma;
    float pesos[3] = {2,3,5};

    printf("Digite a quantidade de testes:\n");
    scanf("%i", &n);


    while (n--){
        printf("Digite os numeros para efetuar a media ponderada:\n");
        tt = 3;
        soma = 0;
        while (tt--){
            scanf("%f", &num);
            soma += num*pesos[3-tt-1];
        }
        printf("Media ponderada = %.1f\n\n", (soma/10));
    }

return 0;
}
