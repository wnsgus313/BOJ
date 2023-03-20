#include <cstdio>

int year, res;

int main(){
  scanf("%d", &year);
  if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
    res = 1;
  }

  printf("%d", res);
}