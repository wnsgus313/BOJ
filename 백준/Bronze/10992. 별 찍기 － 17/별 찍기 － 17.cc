#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  for(int i=1; i<=n-1; i++){
    for(int j=1; j<=n-i; j++)
      printf(" ");
    printf("*");

    for(int j=1; j<=2*i-3; j++)
      printf(" ");
    
    if(i!=1) printf("*");
    printf("\n");
  }
  for(int i=1; i<=2*n-1; i++)
    printf("*");
}