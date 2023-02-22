#include <stdio.h>
#include <string.h>

int main()
{
  char ch[101] = {'0'};
  int place[27] = {0};
  scanf("%s", ch);

  for(int i=0; i<26; i++)
    place[i] = -1;

  for(int i=0; i<strlen(ch); i++){
    int temp = ch[i] - 'a';

    if(place[temp] == -1)
      place[temp] = i;
  }

  for(int i=0; i<26; i++)
    printf("%d ", place[i]);

  return 0;
}