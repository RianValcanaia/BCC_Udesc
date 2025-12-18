/*10. Escreva uma funcao que inverte a ordem dos caracteres de uma string.*/
#include <stdio.h>
#include <stdlib.h>
const int TAM = 200;

void inverte (char s[]){
    int i=0, k=0;
    char temp;

    while(s[k]!=0)k++;
    k--;
    while (i<k){
        temp = s[k];
        s[k] = s[i];
        s[i] = temp;
        i++;
        k--;
    }
}

int main(){
    char s[TAM];
    printf("Digite uma string:\n");
    scanf(" %[^\n]s", s);

    inverte(s);

    printf("%s\n", s);

return 0;
}


