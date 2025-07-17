#include <stdio.h>


void limparTerminal() {
    printf("\033[H\033[J"); // Sequência de escape ANSI para limpar o terminal
}

int main(){
    int n, m;
    double valor, conversao; 

    printf("1) Cotação do dia\n2) Conversão de um valor de moeda estrangeira para real;\n3) Conversão de real para outra moeda;\n");      
    scanf("%d", &n);
    limparTerminal();
    
    if(n==1){
        printf("Opção não estabelecida.");
    } else if (n==2){
        printf("Escolha a opção:\n1) Euro;\n2) Dólar;\n3) Libra;\n4) Rublo;\n5) Iene.\n");
        scanf("%i", &m);
        printf("Digite o Valor: ");
        scanf("%lf", &valor);
        limparTerminal();

        switch (m){
            case 1: 
            conversao = valor*5.12;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 2:
            conversao = valor*5.16;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 3: 
            conversao = valor*5.93;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 4:
            conversao = valor*0.0084;
            printf("Valor convertido = %.2lf\n", conversao);
            break;
            
            case 5:
            conversao = valor*0.037;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            default: 
            printf("Opção inválida!");
        }

    } else if (n==3) {
        printf("Escolha a opção:\n1) Euro;\n2) Dólar;\n3) Libra;\n4) Rublo;\n5) Iene.\n");
        scanf("%i", &m);
        printf("Digite o Valor: ");
        scanf("%lf", &valor);
        limparTerminal();

        switch (m){
            case 1:
            conversao = valor/5.12;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 2:
            conversao = valor/5.16;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 3: 
            conversao = valor/5.93;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            case 4:
            conversao = valor/0.0084;
            printf("Valor convertido = %.2lf\n", conversao);
            break;
            
            case 5:
            conversao = valor/0.037;
            printf("Valor convertido = %.2lf\n", conversao);
            break;

            default: 
            printf("Opção inválida!");
        }
    } else {
        printf("Opção inválida!");
    }
    
    



}