#include <cstdio>

int A, B, n, i;

int main(int argc, char* argv[]) {
  scanf("%d", &n);

  for(i=1; i<=n; i++){
    scanf("%d %d", &A, &B);
    printf("Case #%d: %d\n", i, A+B);
  }

  return 0;
}