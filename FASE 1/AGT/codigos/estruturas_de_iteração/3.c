#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 3. Monte um programa que simule um relógio digital como o anterior porém só imprima os “quartos” de hora, ou seja:
// 0:0
// 0:15
// 0:30
// 0:45
// 1:0
// ... ( e assim por diante até 23:45)

int main() {
    for (int i = 0; i <= 23; i++){
        printf("%02i:00\n%02i:15\n%02i:30\n%02i:45\n", i,i,i,i);
    }
return 0;
}