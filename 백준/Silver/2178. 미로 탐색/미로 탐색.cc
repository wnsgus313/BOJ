#include <cstdio>
#include <queue>

using namespace std;
int arr[101][101];
int dist[101][101];
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q; 

int check(int y, int x){
  if(y < 0 || y >= N || x < 0 || x >= M || arr[y][x] == 0) return false;
  return true;
}

void bfs(){
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(check(ny, nx) && !dist[ny][nx]){
        dist[ny][nx] = dist[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
}

int main()
{
  scanf("%d %d", &N, &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  dist[0][0] = 1;
  q.push(make_pair(0, 0));
  bfs();

  printf("%d", dist[N-1][M-1]);
}