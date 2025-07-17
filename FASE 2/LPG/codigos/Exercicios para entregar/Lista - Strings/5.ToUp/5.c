
/*Faca um programa que leia uma cadeia de caracteres e converta todos os caracteres que forem letras minusculas para letras maiusculas. Dica: e preciso fazer uma subtracao no codigo do caractere. Verifique na tabela ASCII e veja qual valor deve ser usado*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int eh_Alfabetico(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    return 0;
}

void maiusculas(char s[]){
    int caracter;

    for (int i = 0; s[i]!=0;i++){
        caracter = s[i];
        if (eh_Alfabetico(caracter)){
            if (caracter >= 'a' && caracter <= 'z') s[i] += ('A'-'a');
        }   
    }
}

int main(){
    char s[TAM];
    puts("Digite a algo para converter para maiusculo ");
    scanf(" %[^\n]s", s);
    
    maiusculas(s);

    printf("%s\n", s);
    

return 0;
}
