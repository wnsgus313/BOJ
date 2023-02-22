#include <iostream>
#include <algorithm>
using namespace std;

int c[4], A[12];
char op[4] = {'+', '-', '*', '/'};
int N, minR = 2000000000, maxR = -2000000000;

int calc(int l, int r, char op){
  int ret = 0;

  switch (op)
  {
    case '+':
      ret = l + r;
      break;
    case '-':
      ret = l - r;
      break;
    case '*':
      ret = l * r;
      break;
    case '/':
      ret = l / r;
      break;
    default:
      ret = 0;
      break;
  }
  return ret;
}

bool check(int idx){
  if(c[idx] == 0) return false;
  return true;
}

void dfs(int opN, int val){
  if(opN == N) {
    minR = min(minR, val);
    maxR = max(maxR, val);
    return;
  }
  for(int i=0; i<4; i++){
    if(check(i)){
      c[i]--;
      int cal = calc(val, A[opN], op[i]);
      dfs(opN + 1, cal);
      c[i]++;
    }
  }

  return;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;

  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<4; i++){
    cin >> c[i];
  }
  dfs(1, A[0]);
  cout << maxR << ' ' << minR;
}