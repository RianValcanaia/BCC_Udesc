/*
Escreva uma funcao que recebe como parametros uma string s e um inteiro n, e retorna nova string nova contendo s repetida n vezes. Por exemplo, s = “Abc” e n = 4 tem como resultado a string “AbcAbcAbcAbc”. Faca o programa principal chamando a funcao. Prototipo da funcao:
char *repetidor( char *s, int n );
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 11234

char *repetidor(char *s, int n ){
    int tam = strlen(s), i, j;
    char *vet = malloc((sizeof(char) * n * tam)+ sizeof(char));
    
    for (i = 0; i < n; i++){
        for (j = 0; s[j] != 0; j++){
            vet[j+(i*tam)] = s[j];
        }
    }
    vet[i*j] = 0;

    return vet;
}

int main(){
    int repeticao, i;
    char string[TAM];
    printf("Digite a string : ");
    scanf("%[^\n]", string);
    printf("Digite quantas vezes quer que repita: ");
    scanf("%i", &repeticao);
    
    char *clone = repetidor(string, repeticao);

    puts("\nString repetida: ");
    printf("%s\n", clone);

    free(clone);

return 0;
}

