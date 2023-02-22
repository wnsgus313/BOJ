#include <stdio.h>

int dp[32] = {1, 0, 3, };

int main()
{
    int n, i, j;
    scanf("%d", &n);

    for(i=4; i<=n; i+=2){
        dp[i] = dp[i-2] * 3;
        for(j=0; j<=i-4; j+=2)
            dp[i] += dp[j] * 2;
    }

    printf("%d", dp[n]);
}
