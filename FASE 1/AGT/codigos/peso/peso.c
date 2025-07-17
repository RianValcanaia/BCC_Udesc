#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){
    printf("Difite sexo e altura (F/M)\n");
    char sexo;
    double altura;
    //int %d; double %lf; float %f; char %c; out presision %.*f
    scanf ("%c %lf", &sexo, &altura);

    if ((sexo == 'F')){
        float pesoidealf = (62.1 * altura)-44.7;
        printf("peso ideal = %.2f\n", pesoidealf);  
    } else if (sexo == 'M'){
        float pesoidealm = (72.7 * altura)-58;
        printf("peso ideal = %.2f\n", pesoidealm);
    } else { 
        printf("Sexo nao reconhecido\n");
    }


}