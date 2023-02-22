#include <stdio.h>

long long dp[101] = {0, 1, 1, 1, 2, 2, };

int main()
{
    int T, i, res;
    scanf("%d", &T);

    while(T != 0){
        scanf("%d", &res);
        for(i=6; i<=res; i++)
            dp[i] = dp[i-1] + dp[i-5];

        printf("%lld\n", dp[res]);
        T--;
    }
}