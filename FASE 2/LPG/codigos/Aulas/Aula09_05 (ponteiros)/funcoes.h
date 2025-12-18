#include <math.h>

#define FUNCOES_H

int mdc(int a, int b){
    int temp;
    while (b!=0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int max(int a, int b){
    if (a>b) return a;
    else return b;
}

int mmc (int a , int b){
    for (int i = 2; i < max(a,b); i++){
        if(a%i==0 && b%i==0) return i;
    }


}


// void converte(int x, int *pH, int *pM, int *pS){
//     *ph = x/3600;
//     int resto = x % 3600;
//     *pM = resto / 60;
//     *ps = resto % 60;
// }