#include <stdio.h>

int N, t, s;

int main(){ 
	scanf("%d", &N);

  while(N--){
    scanf("%1d", &t);
    s += t;
  }
  
  printf("%d\n", s);
}