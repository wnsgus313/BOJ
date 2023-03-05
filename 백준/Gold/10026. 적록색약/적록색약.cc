#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
char arr[101][101];
int visited[101][101];
int res1, res2, N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q;

int check(int y, int x){
  if(y < 0 || y >= N || x < 0 || x >= N || visited[y][x]) return false;
  return true;
}

void bfs(int flag, char color){
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(!flag){
        if(check(ny, nx) && arr[ny][nx] == color){
          visited[ny][nx] = 1;
          q.push(make_pair(ny, nx));
        }
      }
      else{
        if(check(ny, nx)){
          if(color == 'B' && arr[ny][nx] == color){
            visited[ny][nx] = 1;
            q.push(make_pair(ny, nx));
          }
          else if((color == 'G' || color == 'R') && (arr[ny][nx] == 'G' || arr[ny][nx] == 'R')){
            visited[ny][nx] = 1;
            q.push(make_pair(ny, nx));
          }
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(!visited[i][j]){
        visited[i][j] = 1;
        q.push(make_pair(i, j));
        bfs(0, arr[i][j]);
        ++res1;
      }
    }
  }

  memset(visited, 0, sizeof(visited));

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(!visited[i][j]){
        visited[i][j] = 1;
        q.push(make_pair(i, j));
        bfs(1, arr[i][j]);
        ++res2;
      }
    }
  }

  cout << res1 << ' ' << res2;
}