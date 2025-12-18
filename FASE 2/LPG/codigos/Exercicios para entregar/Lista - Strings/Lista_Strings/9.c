/*Escreva uma funcao remove todos os espacos no inicio e no final de uma string (processo e chamado de trimming). Prototipo:
void trim( char srt[] );*/
#include <stdio.h>
#include <stdlib.h>
const int TAM = 200;

void trim (char s[]){
    int i, k = 0;
    while(s[k] == ' ')k++;
    
    for (i = k; s[i] != 0; i++){
        s[i-k]= s[i];
    }
    s[i-k]=0;
    
    for (i = 0; s[i] != 0; i++);

    while (s[i-1] == ' ' && i != 0)i--;
    s[i]=0;

}

int main(){
    char s[TAM];
    printf("Digite uma string:\n");
    scanf(" %[^\n]s", s);

    trim(s);

    printf("%sok\n", s);

return 0;
}


