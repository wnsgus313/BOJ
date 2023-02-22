#include <stdio.h>
#define MOD 1000000000

int dp[100][10];

int main()
{
  int n, i, j;
  int sum = 0;
  
  scanf("%d", &n);

  dp[0][0] = 0;
  for(i=1; i<10; ++i)
    dp[0][i] = 1;

  for(i=1; i<n; ++i){
    for(j=0; j<10; ++j){
      if(j == 0) dp[i][j] = dp[i-1][1] % MOD;
      else if(j == 9) dp[i][j] = dp[i-1][8] % MOD;
      else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
    }
  }

  for(i=0; i<10; ++i){
    sum += dp[n-1][i];
    sum %= MOD;
  }
  printf("%d\n", sum);

  return 0;
}