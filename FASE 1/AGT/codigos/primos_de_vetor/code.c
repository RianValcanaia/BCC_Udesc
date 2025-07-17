#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ehprimo(int num) {
	int i;
    if (num <= 1) {
        return 0;
    } else {
        for (i = 2; i <= (num/2); i++) {
            if (num % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

int main() {
    int i, num;
    int vetor[10], vetorAux1[10], vetorAux2[10];
    int countPrimos = 0;

    for (i = 0; i < 10; i++) {
        scanf("%i", &vetor[i]);
        num = vetor[i];

        if (ehprimo(num)) {
            vetorAux1[countPrimos] = i;  
            vetorAux2[countPrimos] = num;  
            countPrimos++;
        }
    }

    for (i = 0; i < countPrimos; i++) {
        printf("%i:%i\n", vetorAux1[i], vetorAux2[i]);
    }

    return 0;
}
