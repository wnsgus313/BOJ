#include <stdio.h>

int main()
{
  int yen500=500, yen100=100, yen50=50, yen10=10, yen5=5, yen1=1;
  int price = 0;
  int num = 0;
  int changes = 0;

  scanf("%d", &price);

  changes = 1000 - price;

  while(changes >= yen500){
    num += changes / yen500;
    changes %= yen500;
  }
  while(changes >= yen100){
    num += changes / yen100;
    changes %= yen100;
  }
  while(changes >= yen50){
    num += changes / yen50;
    changes %= yen50;
  }
  while(changes >= yen10){
    num += changes / yen10;
    changes %= yen10;
  }
  while(changes >= yen5){
    num += changes / yen5;
    changes %= yen5;
  }
  while(changes >= yen1){
    num += changes / yen1;
    changes %= yen1;
  }
  printf("%d\n", num);

  return 0;
}