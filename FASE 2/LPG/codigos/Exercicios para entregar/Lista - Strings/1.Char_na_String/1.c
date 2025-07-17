/*1. Dados uma string s e um caractere c faca um programa que verifique se s contem c. Dica: a implementacao dentro de uma funcao facilita a definicao da solucao.*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int contemNaString(char str[], char c){
    for (int i = 0; str[i] != 0; i++){
        if (str[i] == c) return 1;
    }
    return 0;
}

int main(){


    char string[TAM], caracter;
    puts("Digite a string:");
    scanf(" %[^\n]s", string);
    puts("Digite o caracter:");
    scanf(" %c", &caracter);

    if (contemNaString(string,caracter)) printf("Caracter '%c' encontrado na string '%s'\n", caracter, string);
    else printf("Caracter '%c' nao encontrado na string '%s'\n", caracter, string);

    
return 0;
}
