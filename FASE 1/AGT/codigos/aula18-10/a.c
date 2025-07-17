#include<stdio.h>

#define TAM 10

int main() {
	int vi[TAM]={13,34,20,28,2,15,1,10,5,50};
	int i, menor, posmenor, aux, iter;

	for (iter = 0; iter < TAM; iter++){
	menor = vi [iter];
	posmenor = iter;
	
	for (i = iter; i < TAM; i++){
		if (vi[i] < menor){
			menor = vi[i];
			posmenor = i;
		}

	}
	
	aux = vi[iter];
	vi[iter] = menor;
	vi[posmenor] = aux;
	
	}


	for (i = 0; i < TAM; i++){
		printf ("%i, ", vi[i]);
	}
	
}
