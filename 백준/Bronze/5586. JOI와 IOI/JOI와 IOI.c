#include <stdio.h>
#include <string.h>

int main()
{
  char alpha[10000];
  int IOI = 0;
  int JOI = 0;

  scanf("%s", alpha);

  for(int i; i<strlen(alpha)-2; i++){
    if(alpha[i]=='I' && alpha[i+1]=='O' && alpha[i+2]=='I')
        IOI++;
    if(alpha[i]=='J' && alpha[i+1]=='O' && alpha[i+2]=='I')
    JOI++;
  }

  printf("%d\n%d", JOI, IOI);

  return 0;
}