#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    int A, B;
    scanf("%d %d", &A, &B);
    printf("Case #%d: %d + %d = %d\n", i, A, B, A+B);
  }

  return 0;
}