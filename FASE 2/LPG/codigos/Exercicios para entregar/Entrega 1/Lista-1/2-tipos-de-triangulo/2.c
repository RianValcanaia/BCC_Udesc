//        Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado
//        A representa o maior dos 3 lados. A seguir, determine o tipo de triangulo que estes tres lados
//        ormam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:
//        - se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
//        - se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
//        - se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
//        - se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
//        - se os tres lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
//        - se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES
       
#include <stdio.h>

void ordena (float *a, float *b, float *c);

int main(){

    float a,b,c;
    
    printf("Digite os lados do triangulo:\n");
    scanf(" %f %f %f", &a, &b, &c);
    ordena(&a, &b, &c);

    if (a >= b+c)
        printf("Nao forma Triangulo.\n");
    else {
        if ((a*a)==((b*b)+(c*c)))
            printf("Triangulo Retangulo.\n");
        if ((a*a)>((b*b)+(c*c)))
            printf("Triangulo Obtusangulo.\n");
        if ((a*a)<((b*b)+(c*c)))
            printf("Triangulo Acutangulo.\n");
        if (a == b && b == c)
            printf("Triangulo Equilatero.\n");
        if ((a == b && a != c) || (b == c && b != a) || (a == c && a != b))
            printf("Triangulo Isosceles.\n");
    }

return 0;
}

void ordena (float *a, float *b, float *c){
    float temp, maior;
    int posMaior;
    float vetor [3] = {*a, *b, *c};

    for (int i = 0; i < 3; i++){
        posMaior = i;
        maior = vetor[i];
            for (int j = i; j < 3; j++){
                if (vetor[j] > maior){
                    maior = vetor[j];
                    posMaior = j;
                }
            }
        temp = vetor[i];
        vetor[i] = vetor[posMaior];
        vetor[posMaior] = temp;
    }

    *a = vetor[0];
    *b = vetor[1];
    *c = vetor[2];
}