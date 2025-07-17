#include <stdio.h>
#include <stdlib.h>

int main() {
	float notaPfn, somaPfn = 0, percentualPfn, mediaPfn, TAM = 15;
	int abaixoPfn = 0, emExamePfn = 0;
	
	float notaAgt, somaAgt = 0, percentualAgt, mediaAgt;
	int abaixoAgt = 0, emExameAgt;
	
	printf("Digite as notas de PFN:\n");
	
	while(TAM--){
		scanf("%f", &notaPfn);
		
		if (notaPfn < 7){
			abaixoPfn++;
            if (notaPfn > 1.7){
                emExamePfn++;
            }
		}
		somaPfn = somaPfn + notaPfn;
	}
	
	printf("Digite as notas de AGT:\n");
	
	TAM = 15;
	while(TAM--){
		scanf("%f", &notaAgt);
		
		if (notaAgt < 7){
			abaixoAgt++;
            if(notaAgt > 1.7){
                emExameAgt++;
            }
		}
		somaAgt = somaAgt + notaAgt;
	}


	percentualPfn = (abaixoPfn*100)/15;
	mediaPfn = somaPfn/(float)15;
	
	percentualAgt = (abaixoAgt*100)/15;
	mediaAgt = somaAgt/(float)15;
	
	printf("PFN\npercentual de medias < 7 em: %.2f\nMedia geral desse grupo: %.2f\ntotal de estudantes em exame: %i\n", percentualPfn, mediaPfn, emExamePfn);
	
	printf("AGT\npercentual de medias < 7 em: %.2f\nMedia geral desse grupo: %.2f\ntotal de estudantes em exame: %i\n", percentualAgt, mediaAgt, emExameAgt);
	
	return 0;
}