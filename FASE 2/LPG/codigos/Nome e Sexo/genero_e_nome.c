#include <stdio.h>
#include "funcoes.h"

int main(){
    char gen;
    char nome[200];

    limparTela();
    printf("Digite o seu nome:\n");
    scanf("%[^\n]s", nome); //vetores sempre sao passados por referencia
    printf("Digite 'f' para feminino e 'm' para masculino:\n");
    gen = entradaGenero();

    if(gen == 'f' || gen == 'm') 
        printf("Ilma. Sra. %s", nome);
    else 
        printf("Ilmo. Sr. %s", nome);

return 0;
}
