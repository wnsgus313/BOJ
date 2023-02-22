#include <stdio.h>
#include <string.h>

int main()
{
  char str[101] = "0";

  scanf("%s", str);

  for(int i=1; i<=strlen(str); i++){
    printf("%c", str[i-1]);

    if(i%10 == 0)
      printf("\n");
  }
}