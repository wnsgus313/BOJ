#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<int> dq;
int cur, i, N, K;
int dist[100001];

int bfs()
{ 
  if(N == K) return 0;
  memset(dist, -1, sizeof(dist));
  dq.push_back(N);
  dist[N] = 0;

  while(dist[K] < 0){
    cur = dq.front();
    dq.pop_front();

    int next[3] = {cur-1, cur+1, cur*2};
    for(i=0; i<3; i++){
      if(next[i] < 0 || next[i] > 100000) continue;
      if(dist[next[i]] > -1) continue;

      if(i < 2){
        if(next[i] == next[i+1]) continue;
        dq.push_back(next[i]);
        dist[next[i]] = dist[cur] + 1;
      }
      else{
        dq.push_front(next[i]);
        dist[next[i]] = dist[cur];
      }
    }
  }
  return dist[K];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  cout << bfs() << '\n';
}