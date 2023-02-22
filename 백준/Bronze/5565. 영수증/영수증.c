#include <stdio.h>

int main()
{
  int num[9] = {0};
  int sum = 0;
  int result = 0;
  int price = 0;

  scanf("%d", &result);

  for(int i=0; i<9; i++){
    scanf("%d", &num[i]);
    sum += num[i];
  }

  price = result - sum;

  printf("%d", price);

  return 0;
}