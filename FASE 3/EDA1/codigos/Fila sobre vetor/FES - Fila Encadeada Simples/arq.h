#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0


typedef struct{ int idade;
		char nome[30];
	}info;
			
struct descFES{ int cauda;
		int frente;
              	info *vet; 
              	int tamVet;
                };


//======================APLICACAO=====================


//======================FILA=====================
struct descFES * cria(int tamVet);
int cheia(struct descFES *pF);
int vazia(struct descFES *pF);
int tamanhoDaFila(struct descFES *pF);
int insere(info *reg, struct descFES *pF);
int remove_(info *reg, struct descFES *pF);
int buscaCauda(info *reg, struct descFES *pF);
int buscaFrente(info *reg, struct descFES *pF);
struct descFES *destroi(struct descFES *pF);











