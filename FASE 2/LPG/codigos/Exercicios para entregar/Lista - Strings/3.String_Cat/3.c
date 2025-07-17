/*3. Escreva uma funcao que implementa o comportamento da funcao strcat(), ou seja, dadas duas strings str1 e str2, a funcao deve concatenar as duas strings e o conteudo deve ficar em str1. Nao utilize funcoes predefinidas. Prototipo:
void concatena( char str1[], char str2[] );*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

void concatena(char str1[], char str2[]){
    int i, j;
    for (i = 0; str1[i] != 0; i++) ;
    for (j = 0; str2[j] != 0; j++) str1[i+j] = str2[j];
    
    str1[i+j] = '\0';
}

int main(){

    char string1[TAM], string2[TAM];
    puts("Digite a string 1:");
    scanf(" %[^\n]s", string1);
    puts("Digite a string 2:");
    scanf(" %[^\n]s", string2);

    concatena(string1,string2);

    printf("%s\n", string1);

return 0;
}
