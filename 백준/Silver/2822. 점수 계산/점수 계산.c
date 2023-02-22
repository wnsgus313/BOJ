#include <stdio.h>
#include <stdlib.h>

int main()
{
  int result = 0;
  int n[8] = {0};
  int temp[8] = {0};
  int i = 0, min = 0;
  int index[5] = {0};
  int index_temp = 0;

  for(int j=0; j<8; j++)
    scanf("%d", &temp[j]);

  while(i<8){
    min = 151;
    for(int j=0; j<8; j++){
      if(min >= temp[j]){
        min = temp[j];
        index[i] = j;
      }
    }
    n[i] = min;
    temp[index[i]] = 151;
    i++;
  }
  for(int j=3; j<7; j++){
    for(int k=3; k<7; k++)
      if(index[k] > index[k+1]){
        index_temp = index[k];
        index[k] = index[k+1];
        index[k+1] = index_temp;
      }
  }

  for(int j=0; j<5; j++)
    result += n[j+3];
  
  printf("%d\n", result);
  for(int j=0; j<5; j++)
    printf("%d ", index[j+3]+1);

  return 0;
}