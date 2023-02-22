#include <cstdio>
#include <cmath>

int A, B, res, i, calc;
int main()
{
  scanf("%d %d", &A, &B);

  for(i=0; i<3; i++){
    calc = A * (B / (int)pow(10, i) % 10);
    printf("%d\n", calc);
    res += calc * pow(10, i);
  }
  printf("%d", res);
}