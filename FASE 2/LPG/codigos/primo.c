#include <stdio.h>
#include <math.h>

int primo (int n){
    
    int primo = 1;
    float r = sqrt (n); // sqrt reduz a iteracao pois nao tera apos a raiz de x numero
    for (int i = 2; i <= r && primo; i++){
        if(n % i == 0){
           primo = 0; 
        }
    }
    
    if (primo) 
        return 1;
    else 
        return 0;
}

int main(){

    int n;
    printf("Digite um valor:\n");

    scanf("%d", &n);

    for (int i = 2; i <= n; i++){
        if(primo(i)){
            printf("%d eh primo\n", i);
        }
    }    

return 0;
}