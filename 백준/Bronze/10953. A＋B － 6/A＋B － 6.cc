#include <cstdio>

int A, B, n, i;
char c;

int main(int argc, char* argv[]) {
  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%1d %1c %1d", &A, &c, &B);
    printf("%d\n", A+B);
  }

  return 0;
}