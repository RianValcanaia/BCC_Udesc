#include<stdio.h>
#include<string.h>

#define L 3
#define C 4

int main(){
	int matriz[L][C], i, j;
	for (int i = 0; i < L; i++){
		for (int j = 0; j < C; j++){
			scanf("%i\n", &matriz[i][j]);
		}
	}

	for (int i = 0; i < L; i++){
		printf("\n");
		for (int j = 0; j < C; j++){
		if (matriz[i][j]>0){
			printf("%i\t", matriz[i][j]);	
			}
		}	
	}

}
