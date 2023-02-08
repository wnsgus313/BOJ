#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, cost, u, v;
vector<pair<int, pair<int, int> > > edges;

struct DisjointSet{
  vector<int> parent, rank;
  DisjointSet(int V) : parent(V+1), rank(V+1, 1){
    for(int i=1; i<=V; i++){
      parent[i] = i;
    }
  }
  int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

int kruskal(){
  int ret = 0, cut = 0;
  DisjointSet sets(N);

  sort(edges.begin(), edges.end());
  for(int i=0; i<edges.size(); i++){
    cost = edges[i].first;
    u = edges[i].second.first; v = edges[i].second.second;

    if(sets.find(u) == sets.find(v)) continue;
    sets.merge(u, v);
    ret += cost;
    cut = max(cut, cost);
  }

  ret -= cut;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> u >> v >> cost;
    edges.push_back(make_pair(cost, make_pair(u, v)));
  }

  cout << kruskal();
}