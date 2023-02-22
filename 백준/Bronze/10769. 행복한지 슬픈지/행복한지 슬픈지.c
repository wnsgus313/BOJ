#include <stdio.h>
#include <string.h>

int main()
{
  char str[256];
  int happy = 0;
  int sad = 0;

  scanf("%[^\n]", str);

  for(int i=0; i<strlen(str)-2; i++){
    if(str[i]==':' && str[i+1]=='-' && str[i+2]==')')
      happy++;
    if(str[i]==':' && str[i+1]=='-' && str[i+2]=='(')
      sad++;
  }
  
  if(happy==0 && sad==0)
    printf("none\n");
  else if(happy == sad)
    printf("unsure\n");
  else if(happy > sad)
    printf("happy\n");
  else
    printf("sad\n");

  return 0;
}