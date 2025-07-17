#include <stdio.h>
#include <stdlib.h>

int numPerfeito(int num, int tt){
    int res = 0;
    while(res != 1 && num <= tt){
        int soma = 0;
        for (int i = 1; i <= num/2; i++){
            if (num % i == 0){
                soma += i;
            }
        }
        if (soma == num){
            res = 1;
        }else {
            num++;
        }
    }
    if (res != 0){
        return num;
    }else{
        return -1;
    }
    
}


int main(){
    int tt;
    scanf("%i", &tt);
    int num = 2;

    while(num <= tt){
        int resultado = numPerfeito(num, tt);
        if (resultado != -1){
            printf("%i\n", resultado);
            num = resultado + 1;
        }else{
            num++;
        }
        
    }

return 0;
}