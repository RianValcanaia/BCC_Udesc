
/*Escreva um programa que converta uma string que contem somente digitos em um valor inteiro (variavel int)*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int eh_Digito(char c){
    if ((c >= '0' && c <= '9')){
        return 1;
    }
    else return 0;
}

int string_de_digitos(char s[]){
    for (int i = 0; s[i] != 0; i++){
        if (!eh_Digito(s[i])) return 0;
    }
    return 1;
}

int charToInt(char c){
    return c - '0';
}

int stringToInt(char s[]){
    int multiplicador = 1, soma = 0, i;
    for (i = 0; s[i] != 0; i++);
    for (i--;i >= 0; i--){
        soma += charToInt(s[i]) * multiplicador;
        multiplicador*=10;
    }

    return soma;
}


int main(){
    char s[TAM];
    puts("Digite a algo para verificar se contem somente digitos: ");
    scanf(" %[^\n]s", s);

    if(string_de_digitos(s)) printf("'%i' convertida para int\n", stringToInt(s));
    else printf("'%s' nao contem somente digitos\n", s);
    

return 0;
}
