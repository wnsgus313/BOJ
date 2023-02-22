#include <stdio.h>
#include <algorithm>

using namespace std;

int n, v[302], dp[302], i;

int main(){
  scanf("%d", &n);

  for(i=1; i<=n; ++i)
    scanf("%d", &v[i]);

  dp[1] = v[1];
  dp[2] = v[1] + v[2];
  
  for(i=3; i<=n; i++){
      dp[i] = max(dp[i-2]+v[i], dp[i-3]+v[i-1]+v[i]);
  }

  printf("%d", dp[n]);
}