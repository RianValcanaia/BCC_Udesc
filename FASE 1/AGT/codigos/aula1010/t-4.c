#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	scanf("%i", &n);
	int a = 0, b = 0,c = 1, d;
	
	
	while(n--){
		a=a+c;
		d=b;
		b=c;
		c=c+d;
	}
	printf("%i", a);



}


