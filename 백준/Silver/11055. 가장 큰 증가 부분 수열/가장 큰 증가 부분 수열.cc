#include <stdio.h>
#include <algorithm>

#define N 1001

int dp[N], arr[N];
int n, i, j, res;

int main()
{
  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
    dp[i] = arr[i];

    for(j=0; j<i; j++){
      if(arr[i] > arr[j]){
        dp[i] = std::max(dp[i], dp[j] + arr[i]);
      }
    }
  }

  printf("%d\n", *std::max_element(dp, dp+n));
}
