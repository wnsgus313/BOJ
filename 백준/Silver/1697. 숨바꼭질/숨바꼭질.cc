#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int N, K, res, v, i;
queue<int> q;
int dist[100001];

int bfs()
{
  if(N == K) return 0;
  q.push(N);

  while(dist[K] == 0){
    int cur = q.front();
    q.pop();
    int next[3] = {cur-1, cur+1, cur*2};

    for(i=0; i<3; i++){
      if(next[i] < 0 || next[i] > 100000) continue;
      if(dist[next[i]] != 0) continue;
      dist[next[i]] = dist[cur] + 1;
      q.push(next[i]);
    }
  } 

  return dist[K];
}

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> N >> K;

  cout << bfs() << '\n';
}