#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int primo (int num){
    int i, ehprimo = 1;
    
    for (i = 2; i <= sqrt(num); i++){
        if (num % i == 0){
            ehprimo = 0;
            break;
        }
    }
    
    return ehprimo;
    
}




int main()
{
    int k, n, cont = 0;
    
    printf("Digite o numero inicial de primos, e a quantidade de primos após o inicial:\n");
    scanf("%i %i", &k, &n);
    
    printf("{");
    
    while(cont < n){
        if (primo(k)){
            (cont == n-1) ? printf("%i} ", k) : printf("%i, ", k);
            cont++;
        }
    
        k++;
    }

    return 0;
}
