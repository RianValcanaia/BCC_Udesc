#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int num;
	float peso;

	scanf("%f", &peso);
	scanf("%i", &num);


	switch (num){
		case 1:
			peso = peso*0.37;
			break;
		case 2:
			peso = peso*0.88;
			break;
		case 3:
			peso = peso*0.38;
			break;
		case 4:
			peso = peso*2.64;
			break;
		case 5:
			peso = peso*1.15;
			break;
		case 6:
			peso = peso*1.17;
			break;
	return 0;
	}

	printf("%.1f", peso);
}
