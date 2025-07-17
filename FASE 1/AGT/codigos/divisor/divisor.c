#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){

    int n;
    scanf ("%d", &n);

    if (n % 2 == 0){
        printf("Divisivel por 2\n");
    } 
    if (n % 3 == 0){
        printf("Divisivel por 3\n");
    } 
    if (n % 5 == 0){
        printf("Divisivel por 5\n");
    }
    if (n % 7 == 0){
        printf("Divisivel por 7\n");
    }

        
}