/*
Faca uma funcao que receba um parametro (por valor) com o total de minutos passados ao longo do dia e receba tambem dois parametros (referencia) no qual deve preencher com o valor da hora e do minuto corrente. Faca um programa que leia do teclado quantos minutos se passaram desde meia-noite e imprima a hora corrente (use a sua funcao)

void cacula_hora(int totalMinutos, int *ph, int *pm);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cacula_hora(int totalMinutos, int *ph, int *pm){
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
}


int main(){
    int tempo, horas, minutos;
    
    printf("Digite o total em minutos: ");
    scanf("%i", &tempo);

    cacula_hora(tempo, &horas, &minutos);

    printf("Sao %.2d:%.2d", horas, minutos);


return 0;
}