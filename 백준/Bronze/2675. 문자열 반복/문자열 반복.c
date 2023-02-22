#include <stdio.h>
#include <string.h>

int main()
{
  char ch[21];
  int n = 0;
  int T = 0;

  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", &T);
    scanf("%s", ch);
    for(int k=0; k<strlen(ch); k++){
      for(int j=0; j<T; j++){
        printf("%c", ch[k]);
      }
    }
    printf("\n");
  }

  return 0;
}