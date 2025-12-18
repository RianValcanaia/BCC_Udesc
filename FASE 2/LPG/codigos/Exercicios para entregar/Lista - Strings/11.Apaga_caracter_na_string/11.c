/*Crie uma funcao que recebe uma string s e um caractere c, e apague todas as ocorrencias de c em s. Exemplo:
Entrada: s = "ManhattanConnection" e c= 'n'
Saida: s = "MahattaCoectio"*/
#include <stdio.h>
#include <stdlib.h>
const int TAM = 200;

void apaga_char_na_string(char s[], char c){
    int i, k=0;
    for (i = 0; s[i] != 0; i++){
        if(s[i]!=c){
            s[i-k] = s[i];
        }else k++;
    }
    s[i-k]=0;
}

int main(){
    char s[TAM], c;
    printf("Digite uma string:\n");
    scanf(" %[^\n]s", s);
    printf("Digite o char para apagar da string:\n");
    scanf(" %c", &c);

    apaga_char_na_string(s,c);
    printf("%s\n", s);

return 0;
}


