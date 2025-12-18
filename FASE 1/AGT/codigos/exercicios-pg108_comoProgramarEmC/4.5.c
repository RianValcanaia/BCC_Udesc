#include <stdio.h>

int main() {
	int valor, soma = 0, contador = 0;
	printf("Digite uma sequencia de inteiros (9999 para encerrar):\n");

	while (scanf("%d", &valor) != EOF && valor != 9999) {
		soma += valor;
		contador++;     
    }

    	if (contador > 0) {
		double media = (double)soma / contador;
        		printf("A media dos valores inseridos e: %.2f\n", media);
	} else {
		printf("Nenhum valor foi inserido.\n");
	}
	return 0;
}