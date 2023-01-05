#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int N, M, A, B, C;
vector<pair<int, int> > adj[501];

vector<long long> bellmanFord(int start){
  vector<long long> upper(N+1, INT_MAX);
  upper[start] = 0;
  bool updated;

  for(int iter=0; iter<N; iter++){
    updated = false;

    for(int here=1; here<=N; here++){
      for(int i=0; i<adj[here].size(); i++){
        int next = adj[here][i].first;
        int cost = adj[here][i].second;

        if(upper[here] != INT_MAX && (upper[here] + cost < upper[next])){
          upper[next] = upper[here] + cost;
          updated = true;
        }
      }
    }
    if(!updated) break;
  }
  if(updated){
    upper.clear();
  }
  return upper;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M;
  for(int i=1; i<=M; i++){
    cin >> A >> B >> C;
    adj[A].push_back(make_pair(B, C));
  }

  vector<long long> ret = bellmanFord(1);

  if(ret.size() == 0){
    cout << -1 << '\n';
  }
  else{
    for(int i=2; i<=N; i++){
      if(ret[i] == INT_MAX){
        cout << -1 << '\n';
      }
      else{
        cout << ret[i] << '\n';
      }
    }
  }
}