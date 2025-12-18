#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i, vogais = 0, letras = 0, pontos = 0;
    char texto[1000];

    // Entrada
    fgets(texto, sizeof(texto), stdin);

    int tam = strlen(texto);

    for (i = 0; i < tam; i++) {
        char caracter = texto[i];
        if (isalpha(caracter)) {
            letras++;
            if (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U' || caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
                vogais++;
            }
        } else if (ispunct(caracter)) {
            pontos++;
        }
    }

    printf("vogais:%i\nletras:%i\npontos:%i\n", vogais, letras, pontos);

    return 0;
}
