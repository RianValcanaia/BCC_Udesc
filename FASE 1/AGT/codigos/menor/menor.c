#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int n;
    int c;

    scanf("%d", &c);
    int vetor[c];

    for (int i = 0; i < c; i++){
        scanf("%d", &vetor[i]);      
    }
    
    int m = vetor[0];
    int p =  vetor[0];

    for(int i = 1; i < c; i++){
         if (vetor[i] > m){
            m = vetor [i];
        }
    }

    for(int i = 1; i < c; i++){
         if (vetor[i] < p){
            p = vetor [i];
        }
    }


    printf ("\nO maior número do conjunto eh: %d\n", m);
    printf ("O menor numero do conjunto eh: %d\n", p);

}
