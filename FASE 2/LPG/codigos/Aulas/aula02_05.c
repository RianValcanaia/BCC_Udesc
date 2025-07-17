#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const int TAM = 200;

char apaga_Char(char s[], char c){
    int tam = strlen(s), j=0;
    char str[tam];

    for (int i = 0; s[i]!=0; i++){
        if (!(s[i]==c)){
            str[j] = s[i];
            j++;
        }
    }
    str[j] = 0;

    return str;
}

void trim(char str[]){
    int k = 0, i;

    while (str[k] == ' ') k++;
        if (k!= 0){
            for (int i = k; str[i]!=0;i++){
                str[i-k] = str[i];
            }
            str[i-k] = 0;    
        }

        for (k = 0; str[k]!=0;k++);

        while (str[k-1] == ' ' && k!=0) k--;
        str[k]=0;
    
}

int main(){
    
    char string[TAM], caracter;
    printf("Digite a string:\n");
    scanf(" %[^\n]", string);
    scanf(" %c", &caracter);
    // printf("%i\n", strlen(string));
    // trim(string);
    // printf("%i\n", strlen(string));
   
    
return 0;
}
