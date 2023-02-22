#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[20001];
priority_queue<pair<int, int> > pq;
int V, E, start, u, v, w, i;

vector<int> dijkstra(){
  vector<int> dist(V+1, 9999999);

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    
    if(dist[here] < cost) continue;
    for(i=0; i<adj[here].size(); i++){
      int next = adj[here][i].first;
      int nextCost = adj[here][i].second;
      if(cost + nextCost < dist[next]){
        dist[next] = cost + nextCost;
        pq.push(make_pair(-dist[next], next));
      }
    }
  }

  return dist;
} 

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E >> start;

  while(E--){
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }

  vector<int> dist = dijkstra();
  
  for(i=1; i<=dist.size()-1; i++){
    if(dist[i] == 9999999){
      cout << "INF\n";
    }
    else{
      cout << dist[i] << '\n';
    }
  }

  return 0;
}