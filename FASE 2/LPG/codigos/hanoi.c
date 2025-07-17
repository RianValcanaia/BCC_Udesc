#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char origem, char destino, char auxiliar){
    if (n==1)
        printf("\nMova o disco 1 da torre %c para a torre %c", origem, destino);
    else{
        hanoi (n-1, origem, auxiliar, destino);
        printf("\nMova o disco %d da torre %c para a torre %c", n, origem, destino);
        hanoi (n-1, auxiliar, destino, origem);
    }
}

int main(){
    int num;
    printf("Digite o numero de discos:\n");
    scanf("%d", &num);
    hanoi (num, 'A', 'C', 'B');



return 0;
}