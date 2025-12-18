#include "arq.h"

void status(struct descFEC *pF)
{ 	printf("\n\n tamanho do vetor %i --- tamanho da fila %i --- cauda %i --- frente %i \n\n",pF->tamVet,pF->tamFila, pF->cauda, pF->frente);
}

int cheia(struct descFEC *pF)
{ 	
	if (pF->tamFila==pF->tamVet)
		return SIM;
	else
		return NAO;
}

int vazia(struct descFEC *pF)
{
  if (pF->tamFila==0)
    return SIM;
  else
    return NAO;
}

struct descFEC * cria(int tamVet)
{   	struct descFEC *p=NULL;
	p=(struct descFEC *)malloc(sizeof(struct descFEC));
    	if (p)
    	{
		p->vet=(info *)malloc(sizeof(info)*tamVet);//<<<<<<
        	if (p->vet) 
       		     {  p->cauda=-1;
			p->frente=0;
                	p->tamVet=tamVet;
			p->tamFila=0;

            	};
	}
    	return p;
}

int remove_(info *reg, struct descFEC *pF)
{  
    if (pF->tamFila==0)
    	return FRACASSO; //fila vazia
    else
	{	
		memcpy(reg,&(pF->vet[pF->frente]),sizeof(info)); //*reg=pF->vet[pF->frente];	
		pF->frente = (pF->frente+1) % pF->tamVet; // <<<<<<<<<<<<

        	pF->tamFila--; //<<<<<<<<<<<<<<<<<
     	        return SUCESSO;
	}
        
}

int insere(info *reg, struct descFEC *pF)
{    
 
    if (pF->tamFila < pF->tamVet)
    {	 
	pF->cauda = (pF->cauda+1) % pF->tamVet; //<<<<<<<<<<<<<
	memcpy(&(pF->vet[pF->cauda]),reg,sizeof(info)); //pF->vet[pF->cauda]=*reg;
	pF->tamFila++; // <<<<<<<<<<<<<< 
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int buscaCauda(info *reg, struct descFEC *pF)
{  
    if (pF->tamFila > 0)
    {   memcpy(reg, &(pF->vet[pF->cauda]),sizeof(info)); //<<<<<<<<<<<
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int buscaFrente(info *reg, struct descFEC *pF)
{  
    if (pF->tamFila > 0)
    {   memcpy(reg, &(pF->vet[pF->frente]),sizeof(info)); //<<<<<<<<<<<
        return SUCESSO;
    }
    else
        return FRACASSO;
}


struct descFEC* destroi(struct descFEC *pF)
{
  free(pF->vet);
  free(pF);
  return NULL;	
}	


int tamanhoDaFila(struct descFEC *pF)
{ return pF->tamFila;
}








































