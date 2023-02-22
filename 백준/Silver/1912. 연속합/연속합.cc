#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000];
int n, v, res = -10000;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> v;
    dp[i] = max(dp[i-1] + v, v);
  }

  for(int i=0; i<n; i++){
    if(res < dp[i]){
      res = dp[i];
    }
  }
  cout << res;
}