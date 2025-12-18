/*1. Modifique o codigo da questao anterior fazendo com que o programa determine quantas vezes o caractere ocorre na string.*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int vezes_char_na_string(char str[], char c){
    int contador = 0;
    for (int i = 0; str[i] != 0; i++){
        if (str[i] == c) contador++;
    }
    return contador;
}

int main(){


    char string[TAM], caracter;
    puts("Digite a string:");
    scanf(" %[^\n]s", string);
    puts("Digite o caracter:");
    scanf(" %c", &caracter);

    printf("'%c' ocorre %i vez(es) na string '%s'\n", caracter, vezes_char_na_string(string,caracter), string);

    
return 0;
}
