#ifndef FUNCOES_H
#define FUNCOES_H

void limpaTela (){
    printf("\033[H\033[J");
}

void limpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void telaInicial(){
    limpaTela();
    printf("Bem vindo!!\n");
    getchar();
}

void menuInicial(){
    printf("Menu:\n\n");
    printf("[1] - Criar um novo conjunto vazio.\n");
    printf("[2] - Inserir dados em um conjunto.\n");
    printf("[3] - Remover um conjunto.\n");
    printf("[4] - Fazer a uniao entre dois conjuntos.\n");
    printf("[5] - Fazer a intersecao entre dois conjuntos.\n");
    printf("[6] - Mostrar um conjunto.\n");
    printf("[7] - Mostrar todos os conjuntos.\n");
    printf("[8] - Busca por um valor.\n");
    printf("[9] - Sair do programa.\n");
}

int entradaUsuario (int inicioIntervalo, int fimIntervalo,int *entradaNum) {
    while (1) {
        if (scanf("%i", entradaNum) == 1 && *entradaNum >= inicioIntervalo && *entradaNum <= fimIntervalo) {
            break;
        } else {
            if (inicioIntervalo == fimIntervalo) {
                printf("Opcao invalida. Unica opcao valida eh %i.\n", fimIntervalo);
                limpaBuffer();
            }
            else {
                printf("Opcao invalida. Digite um numero de %i a %i.\n", inicioIntervalo, fimIntervalo);
                limpaBuffer();
            }
        }
    }
    return *entradaNum;
}

int tamanho(int vetor[]){
    int contador = 0;
    for (int i = 0; vetor[i] != 0; i++) contador++;
    return contador;
}

int buscaSeq(int vetor[], int num){
    for (int i = 0; vetor[i]!= 0; i++){
        if (vetor[i]==num) return 1;
    }
    return 0;
}

void vetorcpy(int destino[], int origem[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void vetorset(int vetor[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = valor;
    }
}

void matrizset(int linhas, int colunas, int matriz[linhas][colunas], int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = valor;
        }
    }
}

#endif