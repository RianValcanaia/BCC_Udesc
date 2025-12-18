#include <stdio.h>

int main() {
    int casos, i;

    scanf("%d", &casos);
    int res[casos+1];

    for (i = 0; i < casos; i++) {
        int resposta;
        scanf("%d", &resposta);
        res[i] = resposta;
    }

    for (i = 1; i <= casos; i++){
        printf("resposta %d: %d\n", i, res[i-1]);
    }

    return 0;
}
