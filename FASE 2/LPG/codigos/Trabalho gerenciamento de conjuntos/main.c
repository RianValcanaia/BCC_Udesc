#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"
#include "funcoes.h"

const int L = 4, C = 4;

int main(){

    int opcao, continuar = 1, indiceLinhaMatriz = 0;
    int matriz[L][C];
    matrizset(L, C,matriz, 0); //inicia a matriz zerada.   
   
    telaInicial();
    limpaTela();
    
    while (continuar){
        limpaTela();
        menuInicial();
        entradaUsuario(1,9,&opcao);
        switch(opcao){
            case 1:
            limpaTela();
            novoConjunto(L, C, matriz, &indiceLinhaMatriz);
            break;
            case 2: 
            limpaTela();
            inserirDados(L,C,matriz, &indiceLinhaMatriz);
            break;
            case 3:
            limpaTela();
            removerConjunto(L,C,matriz,&indiceLinhaMatriz);
            break;
            case 4:
            limpaTela();
            uniao(L,C,matriz,&indiceLinhaMatriz);
            break;
            case 5:
            // intersecao();
            break;
            case 6:
            // mostrarConjunto();
            break;
            case 7:
            // mostrarTodosOsConjuntos();
            break;
            case 8:
            // buscaValor();
            break;
            case 9:
            limpaTela();
            continuar = 0;
            break;
        }
    }
return 0;
}