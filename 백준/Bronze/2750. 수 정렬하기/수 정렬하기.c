#include <stdio.h>
#include <string.h>

void swap(int n[], int a, int b)
{
  int temp;

  temp = n[a];
  n[a] = n[b];
  n[b] = temp;
}

void quicksort(int n[], int left, int right){
  int pivot, i, j;

  pivot = n[left];
  i = left;
  j = right + 1;

  if(left < right){
    do{
      do i++; while(n[i] < pivot);
      do j--; while(n[j] > pivot);
      if(i < j) swap(n, i, j);
    }while(i<j);

    swap(n, left, j);
    quicksort(n, left, j-1);
    quicksort(n, j+1, right);
  }
}

int main()
{
  int n[1000001];
  int num = 0;
  int len = 0;

  scanf("%d", &num);

  for(int i=1; i<=num; i++){
    scanf("%d", &n[i]);
  }

  quicksort(n, 1, num);

  for(int i=1; i<=num; i++){
    printf("%d\n", n[i]);
  }

  return 0;
}