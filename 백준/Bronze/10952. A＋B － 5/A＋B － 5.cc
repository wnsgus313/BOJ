#include <cstdio>

int A, B;

int main(int argc, char* argv[]) {
  while(1){
    scanf("%d %d", &A, &B);

    if( A==0 && B==0) break;

    printf("%d\n", A+B);
  }

  return 0;
}