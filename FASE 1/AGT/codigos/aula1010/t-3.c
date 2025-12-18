#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	int num, i;
	scanf("%i", &num);

	num++;

	while(1){
		int primo = 1;
		if (num <=1){
			primo = 0;
		}else {
			 for (i = 2; i <= (num/2); i++) {
                if (num % i == 0) {
                    primo = 0; 
                    break;
                }
            }
		}

		if (primo==1) {
            printf("%i", num);
            break;
        }
        
        num++;
	}

return 0;
}
