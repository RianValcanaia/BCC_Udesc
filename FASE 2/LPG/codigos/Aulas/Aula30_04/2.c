/*2. Modifique o código da questão anterior fazendo com que o programa determine quantas
vezes o caractere ocorre na string.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contaCaracter(char string[], char caracter){
    int contador = 0;
    for (int i = 0; string[i] != 0; i++){
        if (string[i] == caracter) contador++;
    }
    return contador;
}

int eh_digito(int caracter){
    if (caracter >= '0' && caracter <= '9' ) return 1;
    else return 0;
}

int contemDigitos(char str[]){
    for (int i = 0; str[i] != 0; i++){
        if (!eh_digito(str[i])) return 0;
    }
    return 1;
}

int charToInt(int caracter){
    return caracter-'0';
}

int strToInt(char str[]){
    int contador = 0;
    int multiplicador = 1;
    for (int i = strlen(str)-1; i >= 0; i--){
        contador += charToInt(str[i])*multiplicador;
        multiplicador *= 10;
    }
    return contador;

}

int main(){

    char string[200], caracter;
    puts("Digite a string:");
    scanf(" %[^\n]s", string);
    /*puts("Digite o caracter:");
    scanf(" %c", &caracter);

    printf("%i\n", contaCaracter(string, caracter));
    printf("%s\n", (contemDigitos(string))? "Contem somente Digitos" : "Nao contem somente digitos");*/
    printf("%i\n",strToInt(string));

return 0;
}

