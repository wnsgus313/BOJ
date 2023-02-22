#include <iostream>
#include <cstdio>

#define MAX 2002

using namespace std;

int N, i, j, M, S, E;
int s[MAX];
int dp[MAX][MAX];

int main() {
  scanf("%d", &N);

  for(i=1; i<=N; i++)
    scanf("%d", &s[i]);

  for(i=1; i<=N; i++)
    dp[1][i] = 1;

  for(i=1; i<=N-1; i++){
    if(s[i] == s[i+1])
      dp[2][i] = 1;
  }

  for(i=3; i<=N; i++){
    for(j=1; j<=N-i+1; j++){
      if((s[j] == s[j+i-1]) && (dp[i-2][j+1] == 1)){
        dp[i][j] = 1;
      }
    }
  }

  scanf("%d", &M);

  for(i=0; i<M; i++){
    scanf("%d %d", &S, &E);
    
    if(dp[E-S+1][S] == 1)
      printf("1\n");
    else
      printf("0\n");
  }
}