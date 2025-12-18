#include "arq.h"
#include "math.h"

void main(void)
{	int tamVet, i;
	info data[]={{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"}}, tmp;
	struct descFES *p=NULL;

	tamVet=sizeof(data)/sizeof(info);

	p=cria(tamVet);
	for(i=0;i<tamVet;i++)
		insere(&data[i], p);
			 
	i= tamanhoDaFila(p);
	printf("tamanho da fila %i\n", i);

	buscaCauda(&tmp,p);
	printf("final da fila %i %s \n", tmp.idade,tmp.nome);

	buscaFrente(&tmp,p);
	printf("frente da fila %i %s \n", tmp.idade,tmp.nome);

	for(i=0; i<round(tamVet/2);i++)
		if (remove_(&tmp,p) == FRACASSO)
			printf("erro na remocao\n");
		else
			printf("Removido da fila %i %s \n", tmp.idade,tmp.nome);
	
	buscaCauda(&tmp,p);
	printf("final da fila %i %s \n", tmp.idade,tmp.nome);

	buscaFrente(&tmp,p);
	printf("frente da fila %i %s \n", tmp.idade,tmp.nome);
	i= tamanhoDaFila(p);
	printf("tamanho da fila %i, tamanho do vetor %i\n", i, tamVet);
	if(insere(&data[0], p)==FRACASSO)
		printf("Erro na tentativa de insercao");
	getchar();
	p=destroi(p);
}





