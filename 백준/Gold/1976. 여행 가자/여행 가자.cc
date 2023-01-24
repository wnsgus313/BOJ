#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet{
  vector<int> parent, rank;
  DisjointSet(int V): parent(V), rank(V, 1){
    for(int i=0; i<V; i++){
      parent[i] = rank[i] = i;
    }
  }

  int find(int u){
    if(u == parent[u]) return u;
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

int N, M, info, plan, first;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M;
  
  DisjointSet st(N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> info;
      if(info == 1){
        st.merge(i, j);
      }
    }
  }

  cin >> plan;
  first = st.find(plan-1);
  for(int i=0; i<M-1; i++){
    cin >> plan;
    if(first != st.find(plan-1)){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}