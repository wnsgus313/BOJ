#include <stdio.h>
#include <string.h>
#include <algorithm>

#define mx 100003

int dp[2][mx];
int arr[2][mx];

int t, n, i, j, res;

int main()
{
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);

    for(i=0; i<2; i++){
      memset(arr[i], 0, sizeof(int)*mx);
      memset(dp[i], 0, sizeof(int)*mx);
    }

    for(i=0; i<2; i++){
      for(j=0; j<n; j++)
        scanf("%d", &arr[i][j]);
    }

    dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
    dp[0][1] = arr[0][1] + arr[1][0]; dp[1][1] = arr[0][0] + arr[1][1];

    for(i=2; i<=n; i++){
      dp[0][i] = std::max(dp[1][i-1], dp[1][i-2]) + arr[0][i];
      dp[1][i] = std::max(dp[0][i-1], dp[0][i-2]) + arr[1][i];
    }

    printf("%d\n", std::max(dp[0][n], dp[1][n]));
  }
}
