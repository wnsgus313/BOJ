#include <iostream>
#include <algorithm>
using namespace std;

int N, res;
int cost[1002][3];
int cache[1002][3];

int dp(int h, int c){
  int& ret = cache[h][c];
  if(ret != 999999999) return ret;

  for(int i=0; i<3; i++){
    if(i == c) continue;
    
    ret = min(ret, dp(h-1, i) + cost[h][c]);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++){
    for(int j=0; j<3; j++){
      cin >> cost[i][j];
      cache[i][j] = 999999999;
    }
  }

  for(int i=0; i<3; i++){
    cache[1][i] = cost[1][i];
  }

  for(int i=0; i<3; i++){
    dp(N, i);
  }

  cout << min(cache[N][0], min(cache[N][1], cache[N][2]));
}