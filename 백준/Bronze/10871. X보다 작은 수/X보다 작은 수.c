#include <stdio.h>

int main()
{
  int n1 = 0, n2 = 0;
  int num = 0;
  int pivot = 0;
  int arr[10000] = {0};

  scanf("%d %d", &num, &pivot);

  for(int i=0; i<num; i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0; i<num; i++){
    if(arr[i] < pivot)
      printf("%d ", arr[i]);
  }

  return 0;
}