#include <iostream>
#include <cstring>

using namespace std;
#define MAX 101
#define MAX_COST 1000000000

int adj[MAX][MAX];
int i, j, k, n, m, a, b, c;

void floyd()
{
  for(k=1; k<=n; k++){
    for(i=1; i<=n; i++){
      for(j=1; j<=n; j++){
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  fill(&adj[0][0], &adj[MAX - 1][MAX], MAX_COST);

  while(m--){
    cin >> a >> b >> c;
    adj[a][b] = min(c, adj[a][b]);
  }

  for(i=1; i<=n; i++) adj[i][i] = 0;

  floyd();

  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      if(adj[i][j] == MAX_COST){
        cout << 0 << ' ';
      }
      else{
        cout << adj[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}