#ifndef CONJUNTOS_H
#define CONJUNTOS_H
#include "funcoes.h"
#include <string.h>

void mostraMatriz(int L, int C, int matriz[L][C]){
    for (int i = 0; i < L; i++){
        printf("[%d] - ", i);
        for (int j = 0; j < C; j++){
            (j==0)? printf("{%d,", matriz[i][j]) : (j==C-1)? printf("%d}", matriz[i][j]) : printf("%d,", matriz[i][j]);
        }
    printf("\n");
    }
}

void novoConjunto(int L, int C, int matriz[L][C], int *indiceLinhaMatriz){
    printf("Digite os numeros do novo conjunto:\n");
    int continuar = 1, num, i=0;
    if (*indiceLinhaMatriz == L-1) {
        printf("Sem espaco na Matriz para alocar o conjunto. Pressione Enter para voltar.\n");
        getchar();
    }else{
        while (continuar && i < C){
            if (scanf("%d",  &num) == 1){
                if (num == 0) continuar = 0;
                else {
                    matriz[*indiceLinhaMatriz][i] = num;
                    i++;
                }
            }else {
                printf("Entrada valida somente para numeros.\n");
            }
        }
        (*indiceLinhaMatriz)++;
    }
}

void inserirDados(int L, int C, int matriz[L][C], int *indiceLinhaMatriz){
    int indice, continuar = 1, num;
    mostraMatriz(L,C, matriz);
    
    
    if (*indiceLinhaMatriz == 0) {
        printf("\nNennhum conjunto adicionado a Matriz. Aperte enter para voltar.\n");
        limpaBuffer();
        getchar();
    }
    else {
        printf("\nDigite o indice do conjunto que deseja inserir elemento:\n");
        entradaUsuario(0, (*indiceLinhaMatriz-1),&indice);
        int elemento = tamanho(matriz[indice]);
        
        printf("Digite os elementos:\n");
        while (continuar && elemento < C){
            if (scanf("%d", &num) == 1 && !buscaSeq(matriz[indice], num) && num != 0){
                matriz[indice][elemento] = num;
                elemento++;
            }else if (num == 0) continuar = 0;
            else{
                printf("%d ja esta no conjunto [%d]. Digite um elemento que nao esta no conjunto.\n", num, indice);
            }
        }
    }
}

void removerConjunto(int L, int C, int matriz[L][C], int *indiceLinhaMatriz) {
    int indice;
    mostraMatriz(L, C, matriz);
    if (*indiceLinhaMatriz == 0) {
        printf("\nNenhum conjunto adicionado à matriz. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        printf("\nDigite o índice do conjunto que deseja eliminar.\n");
        entradaUsuario(0, (*indiceLinhaMatriz - 1), &indice);

        for (int i = indice; i < (*indiceLinhaMatriz - 1); i++) {
            for (int j = 0; j < C; j++) {
                matriz[i][j] = matriz[i + 1][j];
            }
        }
        
        memset(matriz[(*indiceLinhaMatriz - 1)], 0, sizeof(matriz[(*indiceLinhaMatriz - 1)]));
        (*indiceLinhaMatriz)--;
    }
}

void uniao(int L, int C, int matriz[L][C], int *indiceLinhaMatriz) {
    int indiceA, indiceB, matrizAuxiliar[C*2], i;
    mostraMatriz(L,C, matriz);
    vetorset(matrizAuxiliar, 0, tamanho(matrizAuxiliar));

    if (*indiceLinhaMatriz <= 1) {
        printf("\nNecessario ter 2 conjuntos salvos. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else if (*indiceLinhaMatriz == L) {
        printf("Sem espaco na Matriz para alocar o conjunto. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        printf("Digite os indice das matrizes para fazer a Uniao:\n");

        entradaUsuario(0,*indiceLinhaMatriz-1, &indiceA);
        entradaUsuario(0,*indiceLinhaMatriz-1, &indiceB);
        
        vetorcpy(matrizAuxiliar, matriz[indiceA], tamanho(matriz[indiceA]));

        int j = tamanho(matrizAuxiliar);

        for (i = 0; matriz[indiceB][i] != 0; i++) {
            if (!buscaSeq(matrizAuxiliar, matriz[indiceB][i])) {
                matrizAuxiliar[j] = matriz[indiceB][i];
                j++;
            }
        }

        if (j <= C) {
            vetorcpy(matriz[*indiceLinhaMatriz], matrizAuxiliar, C);
            (*indiceLinhaMatriz)++;
        } else {
            printf("Conjunto uniao excede a capacidade de alocacao na memoria disponivel. Aperte enter para voltar.\n");
            getchar();
        }
    }
}


#endif
