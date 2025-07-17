#include <stdio.h>

int main(){
    int a, b, c;
    
    printf("Digite os lados do triângulo\n");
    
    scanf("%d %d %d", &a, &b,&c);
    
    if (a>=b+c || b>=a+c || c>=a+b){
        printf("Nao eh triangulo.\n");
        return 0;
    }else{
        if (a==b && b==c) 
            printf ("Tringulo equilatero.\n");
        else if (a==b || b==c || a==c) 
            printf("Triangulo Isosceles.\n");
        else 
            printf("Triangulo Escaleno.\n");
    }
    
    return 0;
}
