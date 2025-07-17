#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){
    int opcao;
    double valor, conversao;
    printf("_______________\nEscolha a opção\n_______________\n\n1) Cotação do dia;\n2) Conversão de um valor de moeda estrangeira para real;\n3) Conversão de real para outra moeda.\n\nDigite o número correspondente a opção: ");
    scanf ("%d", &opcao);

    if (opcao == 2){
        int opcao2;
        printf("______________________\n\n1) De Euro para real;\n2) De Dólar para Real;\n3) De Libra para Real;\n4) De Rublo para real;\n5) De Iene para Real.\n\nDigite o número da opção: ");
        scanf ("%d", &opcao2);
            switch (opcao2){
                case 1:
                    printf("\nDigite o valor em Euros: ");
                        //int %d; double %lf; float %f; char %c; out presision %.*f
                        scanf ("%lf", &valor);
                        conversao = valor * 5.12;
                        printf("O valor em Reais: R$ %.2lf\n", conversao);            
                break;
        
                case 2:
                    printf("\nDigite o valor em Dólar: ");
                        scanf ("%lf", &valor);
                        conversao = valor * 5.16;
                        printf("O valor em Reais: R$ %.2lf\n", conversao);
                break;
                case 3:
                    printf("\nDigite o valor em Libra: ");
                        scanf ("%lf", &valor);
                        conversao = valor * 5.93;
                        printf("O valor em Reais: R$ %.2lf\n", conversao);
                break;
                case 4:
                    printf("\nDigite o valor em Rublo: ");
                        scanf ("%lf", &valor);
                        conversao = valor * 0.0084;
                        printf("O valor em Reais: R$ %.2lf\n", conversao);
                break;
                case 5:
                    printf("\nDigite o valor em Iene: ");
                        scanf ("%lf", &valor);
                        conversao = valor * 0.0037;
                        printf("O valor em Reais: R$ %.2lf\n", conversao);
                break;
        }
    }  
    if (opcao == 3){
        int opcao2;
        printf("1) De Real para Euro;\n2) De Real para Dólar;\n3) De Real para Libra;\n4) De Real para Rublo;\n5) De Real para Iene.\n\nDigite o número da opção:");
        scanf ("%d", &opcao2);
            switch (opcao2){
                case 1:
                    printf("\nDigite o valor:");
                    scanf ("%lf", &valor);
                    conversao = valor/5.12;
                    printf("\nO valor em Euros é: € %.2lf\n", conversao);
                break;

                case 2:
                    printf("\nDigite o valor: ");
                    scanf ("%lf", &valor);
                    conversao = valor/5.16;
                    printf("\nO valor em Dolar é: US$ %.2lf\n", conversao);
                break;

                case 3:
                    printf("\nDigite o valor: ");
                    scanf ("%lf", &valor);
                    conversao = valor/5.93;
                    printf("\nO valor em Libras é: £ %.2lf\n", conversao);
                break;

                case 4:
                    printf("\nDigite o valor: ");
                    scanf ("%lf", &valor);
                    conversao = valor/0.0084;
                    printf("\nO valor em Rublo é: %.2lf ₽\n", conversao);
                break;

                case 5:
                    printf("\nDigite o valor: ");
                    scanf ("%lf", &valor);
                    conversao = valor/0.0037;
                    printf("\nO valor em Iene é: ¥ %.2lf\n", conversao);
                break;
            }
        
}
}