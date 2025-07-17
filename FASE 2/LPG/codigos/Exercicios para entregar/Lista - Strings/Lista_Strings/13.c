/*Escreva uma funcao que, a partir de uma string str, copia para o parametro sub a substring a partir do indice inicial ini e que contem a quantidade de caracteres n. Alguns casos particulares devem ser considerados, conforme os exemplos a seguir. 
Prototipo: void substring( char str[], int ini, int n, char sub[] );
Exemplos: considere str = “Alguma Coisa 123”
(1) substring( str, 7, 5, sub ) -> sub = “Coisa”
(2) substring( str, 13, 3, sub ) -> sub = “123”
(3) substring( str, 13, 10, sub ) -> sub = “123” // No máximo vai ate o final de str
(4) substring( str, 20, 5, sub ) -> sub = “” // string vazia, contem somente o '\0*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int TAM = 200;

void substring( char s[], int inicio, int n, char sub[]){
    int i;
    for (i = inicio; i < (inicio + n); i++){
        sub[i-inicio] = s[i];
    }
    sub[i] = 0;
}



int main(){
    int ini, tam;
    char s[TAM], sub[TAM];
    printf("Digite a string:\n");
    scanf(" %[^\n]s", s);
    printf("Digite o inicio e o tamanho da subtring:\n");
    scanf("%i %i", &ini, &tam);

    substring(s,ini,tam,sub);
    printf("%s\n", sub);

return 0;
}


