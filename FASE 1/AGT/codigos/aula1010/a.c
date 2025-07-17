#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int main() {
	
	char nome [200], nome2[100], letra;
	int i, j = 0;

	printf("Digite o seu nome:\n");
	scanf("%[^\n]s", nome);
	
	int tam = strlen(nome);

	for (i=0; i < tam; i++){
		letra = nome[i];
		if (isspace(letra) == 0){
			nome2[j] = nome[i];
			j++;
		}

	}


	printf("%s", nome2);

}
