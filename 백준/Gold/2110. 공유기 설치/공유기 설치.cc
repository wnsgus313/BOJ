#include <iostream>
#include <algorithm>

using namespace std;

int N, C, i, t, res, d;
int x[200000];

void binarySearch(int left, int right){
  if(left > right) return;
  
  int dis = (right + left) / 2;
  int c = C;

  c--;
  d = 0;
  for(i=1; i<N; i++){
    d += x[i] - x[i-1];
    if(d >= dis){
      c--; d = 0; 
    }
  }

  if(c > 0){
    binarySearch(left, dis-1);
  }
  else if(c <= 0){
    if(dis > res) {
      res = dis;
    }
    binarySearch(dis+1, right);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> C;
  for(i=0; i<N; i++){
    cin >> t;
    x[i] = t;
  }
  sort(x, x + N);
  binarySearch(1, x[N-1]);
  cout << res;
}