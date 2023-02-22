#include <stdio.h>

int dp[1001] = {0, 1, 3};
int n;

int main(){
  scanf("%d", &n);

  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2]*2;
    dp[i] %= 10007;
  }

  printf("%d\n", dp[n]);
}