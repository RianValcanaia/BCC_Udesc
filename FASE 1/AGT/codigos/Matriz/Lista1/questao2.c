#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 1005

int vogais(char texto[]){
    int somaVogais = 0;
    int tam = strlen(texto);
    
    for (int i = 0; i < tam; i ++){
        if (strchr("aeiouAEIOU", texto[i])){
            somaVogais++;
        }
    }
    return somaVogais;

}

int letras(char texto[]){
    int somaLetras = 0;
    int tam = strlen(texto);
    
    for (int i = 0; i < tam; i ++){
        if (isalpha(texto[i])){
            somaLetras++;
        }
    }
    return somaLetras;

}

int pontos(char texto[]){
    int somaPontos = 0;
    int tam = strlen(texto);
    
    for (int i = 0; i < tam; i ++){
        if (ispunct(texto[i])){
            somaPontos++;
        }
    }
    return somaPontos;

}

int espaco(char texto[]){
    int somaEspaco = 0;
    int tam = strlen(texto);
    
    for (int i = 0; i < tam; i ++){
        if (isspace(texto[i]) && texto[i] != '\n'){
            somaEspaco++;
        }
    }
    return somaEspaco;

}

int main(){

    char texto[TAM];
    fgets(texto, TAM ,stdin);
    printf("Vogais: %d\n\nLetras: %d\n\nPontuacao: %d\n\nBrancos: %d\n", vogais(texto), letras(texto), pontos(texto), espaco(texto));

return 0;
}