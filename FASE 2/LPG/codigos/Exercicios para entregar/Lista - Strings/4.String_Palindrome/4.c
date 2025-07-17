/*4. Escreva um programa que leia uma string e determina se a mesma e palindrome, ou seja, se forma a mesma sequencia de caracteres quando lida de tras para frente. Ex.: ARARA.*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int palindrome(char s[]){
    int i, j = 0;
    for (i = 0; s[i] != 0; i++) j++;
    
    i=0;
    j--;

    while (i<j){
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }

    return 1;
}

int main(){
    char s[TAM];
    puts("Digite a palavra para verificar se eh palindrome: ");
    scanf(" %[^\n]s", s);
    
    if (palindrome(s)) printf("'%s' eh palindrome.\n", s);
    else printf("'%s' nao eh palindrome.\n", s);
    

return 0;
}
