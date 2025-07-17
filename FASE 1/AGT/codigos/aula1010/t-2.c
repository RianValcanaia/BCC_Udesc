#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int num;
	scanf("%i", &num);
	int ans = 1;
	
	if (num ==1){
		ans = 0;
		printf("%i", ans);
	}else{
		for (int i = 2; i <= (num/2); i++){
			if (num % i == 0){
				ans = 0;
				break;
		}
	}

	printf("%i", ans);	

	}
}
