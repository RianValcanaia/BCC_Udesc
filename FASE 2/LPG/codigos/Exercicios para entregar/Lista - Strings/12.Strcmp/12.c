/*Escreva uma funcao que implementa o comportamento da funcao strcmp(), ou seja, dadas duas strings str1 e str2, a funcao deve comparar os conteudos considerando a ordem alfabetica. Prototipo:
int compara( char str1[], char str2[] );*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int TAM = 200;

int compara(char s1[], char s2[]){
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) 
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

int main(){
    char s1[TAM], s2[TAM];
    printf("Digite a string 1:\n");
    scanf(" %[^\n]s", s1);
    printf("Digite a string 2:\n");
    scanf(" %[^\n]s", &s2);

    printf("%i\n%i\n", compara(s1,s2), strcmp(s1,s2));

return 0;
}


