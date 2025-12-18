#include <stdio.h>

int main(){

    float x, y;

    printf("Digite x:\n");
    scanf(" %f", &x);
    printf("Digite y:\n");
    scanf(" %f", &y);

    if (x==y && x==0)
        printf("Origem\n");
    else if (x==0)
        printf("Eixo Y\n");
    else if (y==0)
        printf("Eixo X\n");
    else if (x>0){
        if (y>0)
            printf("Q1\n");
        else
            printf("Q4\n");
    }
    else if (x<0){
        if (y>0)
            printf("Q2\n");
        else 
            printf("Q3\n");
    }
    
    return 0;
}   