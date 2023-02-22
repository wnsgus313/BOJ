#include <stdio.h>
#define MOD 10007

int dp[1001][10];
int sum = 0;

int main()
{
  int n, i, j, k;
  
  scanf("%d", &n);

  dp[0][0] = 1;
  for(i=0; i<10; dp[1][i++] = 1);
  for(i=2; i<=n; ++i){
     for(j=0; j<10; ++j){
        for(k=j; k<10; ++k){
          dp[i][j] += dp[i-1][k];
          dp[i][j] %= MOD;
        }
     }
  }

  for(i=0; i<10; ++i){
    sum += dp[n][i];
    sum %= MOD;
  }

  printf("%d\n", sum);

  return 0;
}