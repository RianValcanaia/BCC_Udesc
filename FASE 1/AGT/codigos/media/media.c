#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){
    int ava;
    char nome[200];
    

    printf("Qual o seu nome: ");
    scanf("%s", nome);

    printf("\nDigite a quantidade de notas avaliativas: ");
    scanf("%d", &ava);

    float notas[ava];
    float ms = 0;
    printf("\nDigite as suas notas: ");
    for(int i = 0; i < ava; i++){
        scanf("%f", &notas[i]); 
        ms = ms + notas[i];
    }
    ms = ms/ava;

    float ef = ((5 * 10 - ms * 6) / 4);
	
    if (ef < 0.00){
    	printf ("\nAprovado\n");
    } else if (ef > 9.95){
        printf ("\nReprovado\n");
    } else {
        printf ("\na sua nota no exame final tera que ser: %.2f ", ef);
    }

}

