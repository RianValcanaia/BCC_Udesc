#include "arq.h"


int cheia(struct descFES *pF)
{ 	
	if (pF->cauda >= pF->tamVet-1)
		return SIM;
	else
		return NAO;
}

int vazia(struct descFES *pF)
{
  if (pF->cauda < pF->frente)
    return SIM;
  else
    return NAO;
}

struct descFES * cria(int tamVet)
{   	struct descFES *p=NULL;
	p=(struct descFES *)malloc(sizeof(struct descFES));
    	if (p)
    	{
		p->vet=(info *)malloc(sizeof(info)*tamVet);//<<<<<<
        	if (p->vet) 
       		     {  p->cauda=-1;
			p->frente=0;
                	p->tamVet=tamVet;

            	};
	}
    	return p;
}

int remove_(info *reg, struct descFES *pF)
{  
    if (pF->cauda < pF->frente)
    	return FRACASSO; //fila vazia
    else
	{
		memcpy(reg,&(pF->vet[pF->frente]),sizeof(info)); //<<<<<<<
        	pF->frente +=1;
     	        return SUCESSO;
	}
        
}

int insere(info *reg, struct descFES *pF)
{    
 
    if (pF->cauda < pF->tamVet-1)
    {	 
	pF->cauda +=1;
	memcpy(&(pF->vet[pF->cauda]),reg,sizeof(info)); //<<<<<<<
	 
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int buscaCauda(info *reg, struct descFES *pF)
{  
    if (pF->cauda >= pF->frente)
    {   memcpy(reg, &(pF->vet[pF->cauda]),sizeof(info)); //<<<<<<<<<<<
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int buscaFrente(info *reg, struct descFES *pF)
{  
    if (pF->cauda >= pF->frente)
    {   memcpy(reg, &(pF->vet[pF->frente]),sizeof(info)); //<<<<<<<<<<<
        return SUCESSO;
    }
    else
        return FRACASSO;
}


struct descFES* destroi(struct descFES *pF)
{
  free(pF->vet);
  free(pF);
  return NULL;	
}	


int tamanhoDaFila(struct descFES *pF)
{ return pF->cauda - pF->frente + 1;
}













