#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int tt = 4;
	int num;
	int ans[5];

	for (int i = 0; i< tt; i++){
		scanf("%i", &num);
		ans [i] = num * num;	
	
	}
	for (int i = 0 ; i < tt; i++){
		printf("%i\n", ans[i]);
	}

}
