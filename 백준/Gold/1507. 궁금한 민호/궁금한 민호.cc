#include <iostream>
#include <algorithm>
using namespace std;

int N, res;
int adj[20][20];
int cost[20][20];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> adj[i][j];
      cost[i][j] = adj[i][j];
    }
  }

  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(i==k || j==k || i==j) continue;
        if(adj[i][j] > adj[i][k] + adj[k][j]){
          cout << -1;
          return 0;
        }
        if(adj[i][j] == adj[i][k] + adj[k][j]) cost[i][j] = 0;
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      res += cost[i][j];
    }
  }
  cout << res;
}