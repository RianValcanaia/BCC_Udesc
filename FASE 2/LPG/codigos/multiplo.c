#include <stdio.h>

int main(){
    int n, x;

    printf("Digite o valor de N:\n");
    scanf("%d", &n);
    printf("Digite o valor de X:\n");
    scanf("%d", &x);

    for (int i = 1; i<=n; i++){
        if(i%x == 0)
            printf("\t%d é multiplo de %d\n", i, x);
        else
            printf("\t%d\n", i);
    }

    return 0;
}