#include <stdio.h>

int main()
{
  int num1 = 0;
  int num2 = 0;
  int stNum1 = 0;
  int stNum2 = 0;
  int a[4] = {0};
  int b[4] = {0};
  int div = 100;
  int mul = 100;
  int temp = 0;

  scanf("%d %d", &num1, &num2);

  temp = num1;
  for(int i=2; i>=0; i--){
    a[i] = temp / div;
    temp %= div;
    div /= 10;
  }

  div = 100;
  temp = num2;
  for(int i=2; i>=0; i--){
    b[i] = temp / div;
    temp %= div;
    div /= 10;
  }

  for(int i=0; i<3; i++){
    stNum1 += a[i] * mul;
    mul /= 10;
  }

  mul = 100;
  for(int i=0; i<3; i++){
    stNum2 += b[i] * mul;
    mul /= 10;
  }

  if(stNum1 >= stNum2)
    printf("%d\n", stNum1);
  else
    printf("%d\n", stNum2);

  return 0;
}