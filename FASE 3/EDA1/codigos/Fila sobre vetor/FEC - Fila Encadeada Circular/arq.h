#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0
#define DEBUG

typedef struct{ int idade;
		char nome[30];
	}info;
			
struct descFEC{ int cauda;
		int frente;
              	info *vet; 
              	int tamVet;
		int tamFila;
                };


//======================APLICACAO=====================
void exibeInfo(char *msg, info *reg);

//======================FILA=====================
struct descFEC * cria(int tamVet);
int cheia(struct descFEC *pF);
int vazia(struct descFEC *pF);
int tamanhoDaFila(struct descFEC *pF);
int insere(info *reg, struct descFEC *pF);
int remove_(info *reg, struct descFEC *pF);
int buscaCauda(info *reg, struct descFEC *pF);
int buscaFrente(info *reg, struct descFEC *pF);
struct descFEC *destroi(struct descFEC *pF);
void status(struct descFEC *pF);











