//        Escreva uma função que calcula o somatório dos n termos que são múltiplos de k a partir
//        de x. Os parâmetros são determinados pelo usuário e a função é chamada pelo programa
//        principal, que em seguida mostra o resultado na tela. Exemplo: para n = 3, k = 4 e x = 18,
//        temos, 20 + 24 + 28 = 72. Protótipo da função:
//                            int soma_especial(int n, int k, int x)

#include <stdio.h>

int soma_especial (int n, int k, int x){
    int soma = 0, i = 0;
    while (i < n){
        if (x % k == 0 ){
            soma += x;
            i++;
        }
        x++;
    }
    return soma;
}

int main(){
    int n, k , x;
    
    printf("Digite os n termos, o k que representa os multiplos, e apartir de x:\n");
    scanf("%i %i %i", &n, &k, &x);
    
    printf("%i", soma_especial(n, k, x));
    
    
    return 0;
}