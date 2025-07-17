#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){

	int ava;
	float media;
	char nome;
	float soma = 0;
	
	printf("Digite seu nome: ");
	scanf("%s", &nome);

	printf("Digite a quantidade de avaliacoes: ");
	scanf("%d", &ava);
	
	float notas[ava];

	for (int i = 0; i < ava; i++){
		scanf("%f", &notas[i]);
		soma = soma + notas[i];	
	}

	media = soma/ava;

	//exame final:
	float ef = (50.00 - (media*6.00))/4.00;

	if (media >= 7.00){
		printf("Aprovado com média: %.2f ", media);
	} else {
		if (ef > 9.95){
		printf("Reprovado com média: %.2f", media);
		} else {
			printf("Precisa de nota %.2f para passar na matéria", ef);
		}
	}

	
}
