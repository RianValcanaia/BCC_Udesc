#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double volume;

    scanf("%i", &n);
    volume = 4/3 * M_PI * pow(n,3);
    printf("O volume = %lf", volume);
}