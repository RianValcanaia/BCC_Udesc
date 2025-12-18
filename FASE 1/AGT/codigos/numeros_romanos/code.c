#include<stdio.h>
#include<stdlib.h>

int main() {
    int num, contador = 0, tam, i;
    scanf("%i", &num);
    char vetor[20];

    while(num >= 1000){
        vetor[contador] = 'M';
        contador++;
        num = num - 1000;
    }   

    if(num >= 900){
        vetor[contador] = 'C';
        vetor[contador+1] = 'M';
        contador = contador + 2;
        num = num-900;
    }   

    while (num >= 500){    
        vetor[contador] = 'D';
        contador++;
        num = num-500;
    }

    if(num >= 400){
        vetor[contador] = 'C';
        vetor[contador+1] = 'D';
        contador = contador + 2;
        num = num-400;
    }

    while(num >= 100){
        vetor[contador] = 'C';
        contador++;
        num = num-100;
    }

    if(num >= 90){
        vetor[contador] = 'X';
        vetor[contador+1] = 'C';
        contador = contador + 2;
        num = num - 90;
    }

    while(num >= 50){
        vetor[contador] = 'L';
        contador++;
        num = num-50;
    }

    if(num >= 40){
        vetor[contador] = 'X';
        vetor[contador+1] = 'L';
        contador = contador + 2;
        num = num-40;
    }

    while(num >= 10){
        vetor[contador] = 'X';
        contador++;
        num = num-10;
    }

    if(num >= 9){
        vetor[contador] = 'I';
        vetor[contador + 1] = 'X';
        contador = contador + 2;
        num = 0;
    }

    while(num >= 5){
        vetor[contador] = 'V';
        contador++;
        num = num-5;
    }

    if(num == 4){
        vetor[contador] = 'I';
        vetor[contador+1] = 'V';
        contador = contador + 2;
        num = 0;
    }

    while(num > 0){
        vetor[contador] = 'I';
        contador++;
        num--;
    }

    for(i=0; i < contador; i++){
        printf("%c", vetor[i]);
    }
}
