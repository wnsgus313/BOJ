#include <stdio.h>
#include <algorithm>

int dp[1001];

int main()
{
    int res, i, j;

    scanf("%d", &res);

    for(i=1; i<=res; i++)
        scanf("%d", &dp[i]);

    for(i=2; i<=res; i++)
        for(j=1; j<=i; j++)
            dp[i] = std::max(dp[i], dp[j]+dp[i-j]);
    
    printf("%d", dp[res]);
}