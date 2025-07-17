#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2. Crie um programa que mostre a seguinte seqüência na tela, de 1 até 10:
// 1 X o numero 1:
// 1
// 2 X o numero 2:
// 2  
// 2
// 3 X o numero 3:
// 3 
// 3  
// 3
// ... ( e assim por diante até 10)
int main() {
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j < i; j++){
            printf("%i\n", i);
        }
    }
return 0;
}