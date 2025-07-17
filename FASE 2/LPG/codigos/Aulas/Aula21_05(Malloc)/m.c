#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int *p, n, i;
    printf("Quantos valores\n");
    scanf(" %d", &n);
    
    p = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++){
        printf("P[%d] = ", i);
        scanf("%d", p+i);
    }

    for (int i = 0; i < n; i++){
        printf("P[%d]: %d\n", i, p[i]);
    }
    free(p);
    return 0;
}