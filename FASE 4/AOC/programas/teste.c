#include <stdio.h>

int dr(int num){
	if (num == 0 || num == 1) return 1;
	else return dr(num-1) + dr(num-2);
}

int main(){
	int num;
	scanf("%i", &num);
	printf("%i\n", dr(num));

	return 0;
}
