#include <stdio.h>
int main()
{
  int kind[10] = {0};
  int k = 0;
  int count = 0;
  int num = 0;

  scanf("%d %d", &count, &k);

  for(int i=0; i<count; i++)
    scanf("%d", &kind[i]);

  for(int i=count-1; i>=0; i--){
    while(k >= kind[i]){
      num += k / kind[i];
      k %= kind[i];
    }
  }
  printf("%d\n", num);

  return 0;
}