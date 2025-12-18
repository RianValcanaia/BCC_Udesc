
//              Faca um programa que le os tres lados de um triangulo e determina o seu tipo, conforme
//              codigos a seguir. Os codigos devem ser retornados por uma funcao de tipo int, que recebe
//              os lados do triangulo como parametro. Prototipo da funcao:
//              int tipo_triangulo(float, x, float y, float z);
//              O retorno da funcao deve ser conforme os codigos a seguir:
//              0. Os lados nao formam um triangulo (ou seja, a soma de dois deles e menor ou igual
//              ao outro lado);
//              1. Triangulo equilatero;
//              2. Triangulo isoceles;
//              3. Triangulo escaleno

#include <stdio.h>
#include <stdlib.h>

int tipo_triangulo(float a, float b, float c){
    if (a >= b+c || b >= a+c || c >= a+b)
        return 0;
    else if (a==b && b==c)
        return 1;
    else if (a != b && b != c && a != c)
        return 3;
    else return 2;
    
}
int main(){

    float a, b, c;
    printf("Digite os lados do triangulo:\n");
    scanf("%f %f %f", &a, &b, &c);

    switch(tipo_triangulo(a,b,c)){
        case 0:
        printf("Nao eh triangulo\n");
        break;
        case 1:
        printf("Triangulo equilatero\n");
        break;
        case 2: 
        printf("Triangulo Isoceles\n");
        break;
        case 3:
        printf("Triangulo escaleno:\n");
        break;
    }

return 0;
}