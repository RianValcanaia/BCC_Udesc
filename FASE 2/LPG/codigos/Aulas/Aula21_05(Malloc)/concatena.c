#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatena( char *s1, char *s2 );
void *concatena_V2( char *s1, char *s2 );

int main(int argc, char *argv[]) {
	char a[20] = "Alguma";
	char b[]   = "Coisa";
	
	char *c = concatena_V2( a, " ");
	printf("A: '%s' e B: '%s' e C: '%s'\n", a, b,c );
	
    char *p = c;
    c = concatena_V2(p,b);
    printf("A: '%s' e B: '%s' e C: '%s'\n", a, b,c );
    free(c);
    free(p);
	return 0;
}

void concatena( char *s1, char *s2 ){
	int n = strlen( s1 );
	strcpy( s1 + n , s2 );
}

void *concatena_V2( char *s1, char *s2 ){
	int n1 = strlen(s1);
    int n2 = strlen(s1);

    char *p = malloc(n1+n2+1); // +1 por causa do "\0";
    strcpy(p,s1);
    strcpy(p+n1,s2);
    return p;
}

