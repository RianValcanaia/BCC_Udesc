//        Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que o
//        mesmo pode começar em um dia e terminar em outro, tendo uma duração máxima de 24 horas.


#include <stdio.h>

int main(){

    int inicio, fim, duracao;

    printf("Digite o horario de inicio e de fim respectivamente:\n");
    scanf(" %i %i", &inicio, &fim);

    if (inicio < fim){
        duracao = fim - inicio;
    } else if (inicio > fim)
        duracao = 24 + (fim - inicio);
    else 
        duracao = 24;

    printf("O JOGO DUROU %i HORA(S)\n", duracao);




return 0;
}