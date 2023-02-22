#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MOD 1000000
int dp[5001];
char dpc[5001];

int main()
{
    int res, i, temp;

    scanf("%s", dpc);
    res = strlen(dpc);

    if(dpc[0] == '0'){
        printf("0");
        return 0;
    }
    
    dp[0] = 1, dp[1] = 1;
    for(i=2; i<=res; i++){
        temp = (dpc[i-2]-'0')*10 + (dpc[i-1]-'0');
        if(dpc[i-1] > '0')
            dp[i] = dp[i-1] % MOD;
        if(10<=temp && temp<=26)
            dp[i] = (dp[i-2]+dp[i]) % MOD;  // +=와 %MOD 우선순위 조심
    }
    printf("%d", dp[res]);
    return 0;
}