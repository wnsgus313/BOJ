#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int> > adj[1001];
int N, cnt, A, B, D, i, j, res;
int dist[1001];
queue<int> q;

int bfs(int a, int b) {
  memset(dist, -1, sizeof(dist));
  q.push(a);
  dist[a] = 0;

  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto next : adj[node]) {
      if(dist[next.first] != -1) continue;
      dist[next.first] = dist[node] + next.second;
      q.push(next.first);
    }
  }
  return dist[b];
}

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> N >> cnt;
  for(i=0; i<N-1; i++){
    cin >> A >> B >> D;
    adj[A].push_back(make_pair(B, D));
    adj[B].push_back(make_pair(A, D));
  }

  for(i=0; i<cnt; i++) {
    cin >> A >> B;
    cout << bfs(A, B) << '\n';
  }
}