//               Escreva um programa que informa se um caractere digitado pelo usuario representa um
//               digito de 0 a 9. A verificacao deve ser feita por uma funcao booleana (int) que recebe um
//               char como parametro. Caso o caractere seja um digito, converta-o para um valor inteiro e
//               o armazene em uma variavel int. Em seguida, mostre o valor inteiro na tela

#include <stdio.h>
#include <stdlib.h>

int verifica(char a){
    if (a >= '0' && a <= '9'){
        int b = a - 48;
        return b;
    }else{
        return -1;
    }
}

int main(){

    char a;
    printf("Digite o numero para verificacao:\n");
    scanf("%c", &a);

    (verifica(a)==-1) ? printf("Nao eh um inteiro entre 0 e 9\n") : printf("%i\n", verifica(a));

return 0;
}