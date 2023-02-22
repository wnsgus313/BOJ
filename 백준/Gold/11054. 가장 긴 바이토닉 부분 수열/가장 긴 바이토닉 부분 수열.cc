#include <stdio.h>
#include <algorithm>

#define N 1001

int dp[N], dp2[N], arr[N];
int n, i, j, res = 0;

int main()
{
  scanf("%d", &n);

  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);

  for(i=0; i<n; i++){
    dp[i] = 1;

    for(j=0; j<i; j++){
      if(arr[i] > arr[j]){
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }


  for(i=n-1; i>=0; i--){
    dp2[i] = 1;

    for(j=n-1; j>=i; j--){
      if(arr[i] > arr[j]){
        dp2[i] = std::max(dp2[i], dp2[j] + 1);
      }
    }
  }

  for(i=0; i<n; i++)
    res = std::max(dp[i]+dp2[i], res);

  printf("%d\n", res - 1);
}