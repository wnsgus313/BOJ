#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int V, E, u, v, w, x, y, M, S, res=INT_MAX;
vector<pair<int, int> > adj[10002];
int mArea, sArea;

vector<int> dijkstra(int start){
  vector<int> dist(V+1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while(!pq.empty()){
    int cost = pq.top().first;
    int here = pq.top().second;
    
    pq.pop();
    if(dist[here] < cost) continue;
    for(int i=0; i<adj[here].size(); i++){
      int next = adj[here][i].first;
      int nextDist = cost + adj[here][i].second;

      if(nextDist < dist[next]){
        dist[next] = nextDist;
        pq.push(make_pair(nextDist, next));
      }
    }
  }

  return dist;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> V >> E;
  for(int i=0; i<E; i++){
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  
  cin >> M >> x;
  for(int i=0; i<M; i++){
    cin >> mArea;
    adj[0].push_back(make_pair(mArea, 0));
  }

  vector<int> mDist = dijkstra(0);
  adj[0].clear();

  cin >> S >> y;
  for(int i=0; i<S; i++){
    cin >> sArea;
    adj[0].push_back(make_pair(sArea, 0));
  }
  
  vector<int> sDist = dijkstra(0);

  for(int i=1; i<=V; i++){
    if((0 < mDist[i] && mDist[i] <= x) && (0 < sDist[i] && sDist[i] <= y)){
      res = min(res, mDist[i] + sDist[i]);
    }
  }
  
  if(res == INT_MAX){
    cout << -1;
  }
  else{
    cout << res;
  }
}