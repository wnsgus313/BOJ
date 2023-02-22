#include <stdio.h>

int main(void) {
  int a = 100;
  int b = 100;
  int n = 0;
  int vice1 = 0; 
  int vice2 = 0;

  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d %d", &vice1, &vice2);

    if(vice1 > vice2)
      b -= vice1;
    else if(vice1 < vice2)
      a -= vice2;
  }

  printf("%d %d", a, b);

  return 0;
}