#include <stdio.h>

int n, i, j;

int main(){
  scanf("%d", &n);

  for(i=1; i<=n; i++){
    for(j=1; j<=n-i; j++){
      printf(" ");
    }

    for(j=1; j<=i; j++){
      printf("*");
    }

    printf("\n");
  }
}