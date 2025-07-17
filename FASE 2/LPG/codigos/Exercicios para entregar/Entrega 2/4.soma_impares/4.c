//                Faca uma funcao que recebe 2 parametros, x e y, e calcule a soma dos numeros impares
//                entre eles (sem contar com eles mesmos). Repare que a funcao deve levar em conta de
//                que x pode ser maior do que y. Por exemplo, para x = 6 e y = -5, temos a seguinte soma
//                (em ordem crescente): -3 + (-1) + 1 + 3 + 5 = 5. Outro exemplo: para x = 3 e y = 10 temos 5
//                + 7 + 9 = 21.
#include <stdio.h>
#include <stdlib.h>

int somaImpares(int a, int b){
   int temp, i, soma=0;
   
    if (a>b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    for(i = a+1; i < b; i++){
        if (i % 2 != 0)
        soma += i;
    }
    return soma;
}
int main(){
    int a,b;
    printf("Digite o dois numeros inteiros:\n");
    scanf("%i %i", &a, &b);

    printf("%i\n", somaImpares(a, b));
return 0;
}