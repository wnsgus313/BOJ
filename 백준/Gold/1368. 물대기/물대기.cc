#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cost;
vector<pair<int, int> > adj[301];

struct DisjointSet{
  vector<int> parent, rank;
  DisjointSet(int V): parent(V+1), rank(V+1, 1){
    for(int i=0; i<=V; i++){
      parent[i] = i;
    }
  };
  int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  };
  void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  };
};

int kruskal(){
  int ret = 0;
  vector<pair<int, pair<int, int> > > edges;
  for(int u=0; u<=N; u++){
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i].first; cost = adj[u][i].second;
      edges.push_back(make_pair(cost, make_pair(u, v)));
    }
  }

  sort(edges.begin(), edges.end());

  DisjointSet sets(N);

  for(int i=0; i<edges.size(); i++){
    int cost = edges[i].first;
    int u = edges[i].second.first, v = edges[i].second.second;

    if(sets.find(u) == sets.find(v)) continue;
    sets.merge(u, v);

    ret += cost;
  }
  
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;

  for(int i=1; i<=N; i++){
    cin >> cost;
    adj[0].push_back(make_pair(i, cost));
  }

  for(int u=1; u<=N; u++){
    for(int i=1; i<=N; i++){
      cin >> cost;
      adj[u].push_back(make_pair(i, cost));
    }
  }

  cout << kruskal();
}