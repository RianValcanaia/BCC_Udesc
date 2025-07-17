#include <stdio.h>

int main() {
    int num, contador = 0, i;
    scanf("%d", &num);
    char vetor[20]; 

    while (num >= 1000) {
        vetor[contador] = 'M';
        contador++;
        num -= 1000;
    }

    if (num >= 900) {
        vetor[contador] = 'C';
        vetor[contador + 1] = 'M';
        contador += 2;
        num -= 900;
    }

    while (num >= 500) {
        vetor[contador] = 'D';
        contador++;
        num -= 500;
    }

    if (num >= 400) {
        vetor[contador] = 'C';
        vetor[contador + 1] = 'D';
        contador += 2;
        num -= 400;
    }

    while (num >= 100) {
        vetor[contador] = 'C';
        contador++;
        num -= 100;
    }

    if (num >= 90) {
        vetor[contador] = 'X';
        vetor[contador + 1] = 'C';
        contador += 2;
        num -= 90;
    }

    while (num >= 50) {
        vetor[contador] = 'L';
        contador++;
        num -= 50;
    }

    if (num >= 40) {
        vetor[contador] = 'X';
        vetor[contador + 1] = 'L';
        contador += 2;
        num -= 40;
    }

    while (num >= 10) {
        vetor[contador] = 'X';
        contador++;
        num -= 10;
    }

    if (num >= 9) {
        vetor[contador] = 'I';
        vetor[contador + 1] = 'X';
        contador += 2;
        num -= 9;
    }

    while (num >= 5) {
        vetor[contador] = 'V';
        contador++;
        num -= 5;
    }

    if (num == 4) {
        vetor[contador] = 'I';
        vetor[contador + 1] = 'V';
        contador += 2;
        num = 0;
    }

    while (num > 0) {
        vetor[contador] = 'I';
        contador++;
        num--;
    }

    for (i = 0; i < contador; i++) {
        printf("%c", vetor[i]);
    }

    printf("\n"); 

    return 0;
}
