#include <cstdio>

int main() {
  char s[101];

  while( gets(s) ){
    printf("%s\n", &s);
  }

  return 0;
}