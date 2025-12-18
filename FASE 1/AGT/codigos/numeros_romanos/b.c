#include <stdio.h>
#include <stdlib.h>

#define TAM 13

int main() {
    int num, contador;

    scanf("%i", &num);
    
    int valores[TAM] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char romanos[TAM][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    char final[20];    

    for (int i = 0; i < TAM; i++){

        while(num >= valores[i]){
            printf("%s", romanos[i]);
            contador++;
            num -= valores[i];
        }
    }

    return 0;
}
