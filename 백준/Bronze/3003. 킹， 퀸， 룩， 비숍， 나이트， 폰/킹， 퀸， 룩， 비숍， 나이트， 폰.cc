#include <cstdio>

int c[6] = {1, 1, 2, 2, 2, 8};
int n, i;
int main()
{
  for(i=0; i<6; i++){
    scanf("%d", &n);
    c[i] -= n;
  }

  for(i=0; i<6; i++){
    printf("%d ", c[i]);
  }
}