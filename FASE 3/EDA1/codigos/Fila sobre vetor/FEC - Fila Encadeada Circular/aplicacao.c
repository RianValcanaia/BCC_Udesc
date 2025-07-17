#include "arq.h"
#include "math.h"

#ifdef DEBUG
#endif

void exibeInfo(char *msg, info *reg){
	//const char *format= strcat("\n",   strcat(msg,"\n nome: %s, idade: %i \n\n")   );
	printf("%s",msg);
	printf("\n nome: %s, idade: %i \n\n",reg->nome, reg->idade);
}

void main(void)
{	int tamVet, i, tam;
	info data[]={{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"}}, tmp;
	struct descFEC *p=NULL;

	tamVet=sizeof(data)/sizeof(info);
	printf("\n\n Instanciando a fila em um vetor de tamanho = %i \n\n", tamVet);
	p=cria(tamVet);

	#ifdef DEBUG
		status(p);
	#endif
	printf("\n\n -----------------inserindo----------------------\n\n");	
	
	for(i=0;i<tamVet;i++)
	{	insere(&data[i], p);
		exibeInfo("inseriu",&data[i]);  //printf("\n inseriu: %s idade %i\n",data[i].nome);
	}		 

	#ifdef DEBUG	
		status(p);
	#endif	

	printf("\n\n -----------------Verificando Cauda/Frente----------------------\n\n");	
	if (buscaCauda(&tmp,p) == SUCESSO)
		exibeInfo("\n\n cauda da fila",&tmp);//printf("\n\n final da fila %i %s \n", tmp.idade,tmp.nome);

	if (buscaFrente(&tmp,p)==SUCESSO)
		exibeInfo("\n\n frente da fila",&tmp);//printf("frente da fila %i %s \n\n", tmp.idade,tmp.nome);

	
	
	
	printf("\n\n tecle alguma coisa...\n");
	getchar();
	
	printf("\n\n----------------- Verificando se está Cheia???? ------------------\n\n");
	if (cheia(p)==SIM)
		printf(" \n\n Fila cheia\n\n");

	printf("\n\n tecle alguma coisa...\n");
	getchar();
			
	printf("\n\n----------------- Tentativa de inserção na fila cheia --------------\n");
	
	#ifdef DEBUG	
		status(p);
	#endif		
	
	if(insere(&data[0], p)==FRACASSO)
		printf("Erro na tentativa de insercao");
	
	printf("\n\n tecle alguma coisa...\n");
	getchar();	
		
		
		
	printf("\n\n -----------------removendo metade dos itens----------------------\n\n");

	tam=tamanhoDaFila(p)/2.0;	
	for(i=0; i<round(tam);i++)
		if (remove_(&tmp,p) == FRACASSO)
			printf("erro na remocao\n");
		else
			exibeInfo("\n\n Removido da fila",&tmp);//printf("\n Removido da fila: %i %s \n", tmp.idade,tmp.nome);
	#ifdef DEBUG	
		status(p);
	#endif	
	
	printf("\n\n -----------------Verificando Cauda/Frente----------------------\n\n");	
	if (buscaCauda(&tmp,p) == SUCESSO)
			exibeInfo("\n\n cauda da fila",&tmp);//printf("\n\n final da fila %i %s \n", tmp.nome);

	if (buscaFrente(&tmp,p)==SUCESSO)
			exibeInfo("\n\n frente da fila",&tmp);//printf(" frente da fila %i %s \n\n", tmp.nome);

	printf("\n\n tecle alguma coisa...\n");
	getchar();
	
	printf("\n\n----------------- inserção *CIRCULANDO* a fila --------------\n");
	tmp.idade=99;
	strcpy(tmp.nome,"Pancho");
	if(insere(&tmp, p)==FRACASSO)
		printf("Erro na tentativa de insercao");
	else
		exibeInfo("inseriu",&tmp); 
			

	
	#ifdef DEBUG	
		status(p);
	#endif

	printf("\n\n tecle alguma coisa...\n");
	getchar();


	printf("\n\n----------------- Remoção de todos os itens *CIRCULANDO* a fila----------------------\n\n");
		

	while(remove_(&tmp,p) == SUCESSO)
		printf("Removido da fila %s \n", tmp.nome);
	
	#ifdef DEBUG	
		status(p);
	#endif
		
	printf("\n\n tecle alguma coisa...\n");
	getchar();
	

	printf("\n tentativa de remocao:\n");
	if(remove_(&tmp,p) ==FRACASSO)
		printf("\n Erro na tentativa de remocao");
	else
		printf("\n Removido da fila %i %s \n", tmp.idade,tmp.nome);
	//getchar();
	


	getchar();
	p=destroi(p);
}





