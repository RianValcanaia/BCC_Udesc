#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main (){
 
    int f = 50;;
    double c;

    while (f <= 100){
    c = (5.00 * (f - 32.00))/9.00;
    printf( "Celsius: %.2lf\n", c);  
    f++;
    


    }
}
