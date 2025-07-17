#include <stdio.h>

int main(){
    float x;
    int n;
    printf("Digite o valor de x:\n");
    scanf("%f", &x);
    printf("Digite o valor de n:\n");
    scanf("%d", &n);
    
    double ex = 0;

    for (int i = 0; i <= n; i++){
        double termo = 1;
        for (int j = 1; j <= i; j++){
            termo *= x/j;
        }
    ex += termo;
    }   

    printf("e elevado a %.3f eh: %.15lf\n", x, ex); //.15lf para mostrar 15 casas decimais




return 0;
}