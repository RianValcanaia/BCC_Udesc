//código selection sort
for (int i = 0; i < tam; i++){
    menor = vetor[i];
    posmenor = i;
        for (int j = i; j < tam; j++){
            if (vetor[j] < menor){
                menor = vetor[j];
                posmenor = j;
            }
        }
    aux = vetor[i];
    vetor[i] = menor;
    vetor[posmenor] = aux;

    //Vetor referencia:
    referencia[i] = i;//esta parte vai no scanf do vetor

    aux = referencia[i];
    referencia[i] = referencia[posMenor];
    referencia[posMenor] = aux;
    //referencia em bubble sort
    aux = referencia[j];
    referencia[j] = referencia[j + 1];
    referencia[j + 1] = aux;
}

//código bubble sort
for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - 1 - i; j++) {
        if (vetor[j] > vetor[j + 1]) {
            aux = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = aux;
        }
    }
}

//linear searh
int res = -1;
    for (int i = 0; i < n; i++) {
        if (vetor[i] == alvo) {
            res = i;
            break;
        }
    }

    if (res != -1) {
        printf("%i\n", res);
    } else {
        printf("Elemento não encontrado.\n");
    }

// busca binária
int esquerda = 0;
int direita = tam - 1;
int res = -1;

while (esquerda <= direita) {
    int meio = (esquerda + direita) / 2;

    if (vetor[meio] == alvo) {
        res = meio;
        break;
    } else if (vetor[meio] < alvo) {
        esquerda = meio + 1;
    } else {
        direita = meio - 1;
    }
}

// saída
if (res != -1) {
    printf("%i\n", res);
} else {
    printf("Elemento não encontrado.\n");
}


//Vetor Frequencias
for (int i = 0; i < tam; i++) {
        scanf("%i", &vetor[i]);
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }

// Crie o vetor de frequência e inicialize com zeros
int frequencia[maximo + 1];
for (int i = 0; i <= maximo; i++) {
    frequencia[i] = 0;
}

// Calcule as frequências
for (int i = 0; i < tam; i++) {
    frequencia[vetor[i]]++;
}

// Exiba as frequências
for (int i = 0; i <= maximo; i++) {
    if (frequencia[i] > 0) {
        printf("[%d]: %d\n", i, frequencia[i]);
    }
}    

<string.h>
strlen(vetor); //tamanho string 
strcat(vetor,vetor); //concatena
strcpy(destino, fonte); //copiar
strcmp(vetor, vetor); //compara string retorna 0 se iguais e -1 caso não sejam iguais;


<ctype.h>
isalpha(caracter); //alfanumerico
isdigit(caracter); //0 a 9;
ispunct(caracter); //todo tipo de ponto;
