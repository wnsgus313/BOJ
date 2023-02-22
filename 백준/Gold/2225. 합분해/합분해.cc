#include <stdio.h>

#define MOD 1000000000
int dp[201][201];

int main()
{
    int N, K, i, j;
    scanf("%d %d", &N, &K);

    for(j=1; j<=K; j++)
        dp[0][j] = 1;
    for(i=1; i<=N; i++){
        for(j=1; j<=K; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
    
    printf("%d", dp[N][K]);
}