#include <stdio.h>

const int N = 101;
char s[N];

int main(){ 
	while( fgets( s, N, stdin )  )
		printf("%s", s);
}