#include <stdio.h>

int fibo(int num) {

    int a = 0, b=1;

    while (b < num){
        int temp = b;
        b = a+b;
        a = temp;
    }
    
    return b==num;
}

int main() {
    int num;
    
    scanf("%d", &num);

    if (fibo(num)) {
        printf("Sim");
    } else {
        printf("Nao");
    }

    return 0;
}
