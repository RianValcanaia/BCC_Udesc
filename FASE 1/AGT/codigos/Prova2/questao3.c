#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 1005

int main() {
    char texto[TAM], textoAuxiliar[TAM], textoInverso[TAM];
    int i, j = 0;
    scanf("%[^\n]s", texto);

    int tamanho = strlen(texto);

    for (i = 0 ; i < tamanho; i++){
        if (isalpha(texto[i])){
            textoAuxiliar[j] = tolower(texto[i]);
            j++;
        }
    }
    textoAuxiliar[j] = '\0';
    
    tamanho = strlen(textoAuxiliar);

    for (i = 0 ; i < tamanho; i++){
       textoInverso[i] = textoAuxiliar[tamanho-i-1];
    }

    textoInverso[tamanho] = '\0';

    if(strcmp(textoAuxiliar, textoInverso) == 0){
        printf("Palindromo= SIM\n");
    }else {
        printf("Palindromo= NAO\n");
    }

}