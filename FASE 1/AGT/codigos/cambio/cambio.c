#include <stdio.h>

int main() {
    int n, moeda_origem, moeda_destino;
    double valor, conversao;

    printf("1) Cotação do dia\n2) Conversão de um valor de moeda estrangeira para real;\n3) Conversão de real para outra moeda;\n");
    scanf("%d", &n);

    if (n == 1) {
        printf("Opção não estabelecida.");
    } else if (n == 2) {
        printf("Escolha a moeda de origem:\n1) Euro;\n2) Dólar;\n3) Libra;\n4) Rublo;\n5) Iene.\n");
        scanf("%d", &moeda_origem);
        printf("Digite o Valor: ");
        scanf("%lf", &valor);

        switch (moeda_origem) {
            case 1:
                conversao = valor * 5.12; // Substitua pelo valor correto
                break;
            case 2:
                conversao = valor * 5.16; // Substitua pelo valor correto
                break;
            case 3:
                conversao = valor * 5.93; // Substitua pelo valor correto
                break;
            case 4:
                conversao = valor * 0.0084; // Substitua pelo valor correto
                break;
            case 5:
                conversao = valor * 0.037; // Substitua pelo valor correto
                break;
            default:
                printf("Opção inválida!");
                return 1; // Saia do programa em caso de opção inválida
        }

        printf("Valor convertido = %.2lf", conversao);
    } else if (n == 3) {
        printf("Escolha a moeda de destino:\n1) Euro;\n2) Dólar;\n3) Libra;\n4) Rublo;\n5) Iene.\n");
        scanf("%d", &moeda_destino);
        printf("Digite o Valor: ");
        scanf("%lf", &valor);

        switch (moeda_destino) {
            case 1:
                conversao = valor / 5.12; // Substitua pelo valor correto
                break;
            case 2:
                conversao = valor / 5.16; // Substitua pelo valor correto
                break;
            case 3:
                conversao = valor / 5.93; // Substitua pelo valor correto
                break;
            case 4:
                conversao = valor / 0.0084; // Substitua pelo valor correto
                break;
            case 5:
                conversao = valor / 0.037; // Substitua pelo valor correto
                break;
            default:
                printf("Opção inválida!");
                return 1; // Saia do programa em caso de opção inválida
        }

        printf("Valor convertido = %.2lf", conversao);
    } else {
        printf("Opção inválida!");
    }

    return 0;
}
