#include <stdio.h>
#include <math.h>

#define TAM 9

int main() {
    int i, j;
    for (i = 0; i < TAM; i++) {
        if (i <= TAM / 2) {
            for (j = 0; j < TAM; j++) {
                if (j < (TAM / 2 - i) || j > (TAM / 2 + i)) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
        } else {
            for (j = 0; j < TAM; j++) {
                if (j < (i - TAM / 2) || j > (TAM - 1 - (i - TAM / 2))) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}