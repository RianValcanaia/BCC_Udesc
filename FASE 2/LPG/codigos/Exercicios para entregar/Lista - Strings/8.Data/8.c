
/*Escreva um programa que leia uma cadeia de caracteres no formato "DD/MM/AAAA" e copie o dia, mes e ano para 3 variaveis inteiras. Antes disso, o programa deve verificar se o
formato esta correto, ou seja, se as barras estao no lugar certo, e se D, M e A sao digitos*/
#include <stdio.h>
#include <stdlib.h>

const int TAM = 200;

int eh_Digito(char c){
    if ((c >= '0' && c <= '9')){
        return 1;
    }
    else return 0;
}

int charToInt(char c){
    return c - '0';
}

int stringToInt(char s[], int inicio, int fim){
    int multiplicador = 1, soma = 0, i;
    for (i=fim;i >= inicio; i--){
        soma += charToInt(s[i]) * multiplicador;
        multiplicador*=10;
    }

    return soma;
}

int formato(char s[]){
    char formato[12] = "xx/xx/xxxx";
    for(int i = 0; s[i]!=0; i++){
        if(formato[i] == 'x'  && !eh_Digito(s[i])) return 0;
        else if (formato[i] == '/' && s[i] != '/') return 0;
        else if (formato[i] == '\0') return 0;
    }
    return 1;
}

int main(){
    char s[TAM];
    int dia, mes, ano;
    puts("Digite a data: ");
    scanf(" %[^\n]s", s);


    if (!formato(s)){
        printf("Data declarada nao esta no padrao dd/mm/aaaa\n");
    }else{
        dia = stringToInt(s,0,1);
        mes = stringToInt(s,3,4);
        ano = stringToInt(s,6,9);
        printf("Data convertida: %d/%d/%d\n", dia, mes, ano);
    }

return 0;
}
