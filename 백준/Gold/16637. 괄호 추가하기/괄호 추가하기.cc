#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, res=INT_MIN;
string s;

int calc(int l, int r, char op){
  int res = l;

  switch (op)
  {
    case '*':
      res = res *= r;
      break;
    case '+':
      res = res += r;
      break;
    case '-':
      res = res -= r;
      break;
  }
  return res;
}

void dfs(int idx, int val){
  if(idx > N - 1) {
    res = max(res, val);
    return;
  }
  
  char op = (idx == 0) ? '+' : s[idx - 1];

  if(idx + 2 < N){
    dfs(idx+4, calc(val, calc(s[idx]-'0', s[idx+2]-'0', s[idx+1]), op));
  }
  dfs(idx+2, calc(val, s[idx]-'0', op));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> s;
  dfs(0, 0);
  cout << res;
}