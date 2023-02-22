#include <stdio.h>
#include <stdlib.h>

int main()
{
  int result = 0;
  int abs1=0, abs2=0;
  int n[3] = {0};
  int temp[3] = {0};
  int i = 0, min = 0;
  int index = 0;

  scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);

  while(i<3){
    min = 101;
    for(int j=0; j<3; j++){
      if(min >= temp[j]){
        min = temp[j];
        index = j;
      }
    }
    n[i] = min;
    temp[index] = 102;
    i++;
  }

  abs1 = abs(n[1] - n[0]);
  abs2 = abs(n[2] - n[1]);

  if(abs1 < abs2)
    result = n[2] - abs1;
  else if (abs1 > abs2)
    result = n[0] + abs2;
  else 
    result = n[2] + abs1;

  printf("%d\n", result);

  return 0;
}