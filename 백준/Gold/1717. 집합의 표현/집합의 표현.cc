#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet{
  vector<int> parent, rank;
  DisjointSet(int V): parent(V+1), rank(V+1, 1){
    for(int i=0; i<=V; i++){
      parent[i] = rank[i] = i;
    }
  }

  int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) ++rank[v];
  }
};

int N, M, op, a, b;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M;
  DisjointSet st(N);

  for(int i=0; i<M; i++){
    cin >> op >> a >> b;
    if(op == 0){
      st.merge(a, b);
    }
    else if(op == 1){
      if(st.find(a) == st.find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}