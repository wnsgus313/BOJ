#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, d, c=1000000001;
long long res, t;
vector<int> dist, cost;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  // 2L -> 4L
  // 2 4 0 0
  // dist : 1 2 3 1
  // cost : 3 5 2 4 1
  // 작아질 때까지 넣어야한다.
  cin >> N;

  dist.resize(N-1);
  cost.resize(N);
  for(int i=0; i<N-1; i++){
    cin >> dist[i];
  }
  for(int i=0; i<N; i++){
    cin >> cost[i];
  }

  for(int i=0; i<N; i++){
    if(cost[i] < c){
      res += c * d;
      c = cost[i];
      d = 0;
    }

    if(i < N-1)
      d += dist[i];
  }
  res += d*c;

  cout << res;
}