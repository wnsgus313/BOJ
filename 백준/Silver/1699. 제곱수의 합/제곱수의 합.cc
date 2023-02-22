#include <stdio.h>
#include <vector>

int dp[100001];
int i, j, n;

int main()
{
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        dp[i] = i;
        for(j=1; j*j<=i; j++){
            dp[i] = std::min(dp[i], dp[i-j*j]+1);
        }
    }

    printf("%d", dp[n]);
    return 0;
}