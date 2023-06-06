// 40분 bfs
// 16분 다익스트라
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int arr[126][126] = {0}; // 도둑루피
int dist[126][126] = {0}; // 거리
priority_queue<pair<int, pair<int, int> > > pq; // {cost, {y, x}}

bool In_Range(int y, int x){
  return 0 <= y && y < N && 0 <= x && x < N;
}

void dijakstra(){
  dist[0][0] = arr[0][0];
  pq.push(make_pair(-dist[0][0], make_pair(0, 0)));

  while(!pq.empty()){
    int y = pq.top().second.first;
    int x = pq.top().second.second;
    int cost = -pq.top().first;
    pq.pop();

    if(dist[y][x] < cost) continue;
    for(int i=0; i<4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(!In_Range(ny, nx)) continue;
      int nCost = cost + arr[ny][nx];

      if(dist[ny][nx] > nCost){
        pq.push(make_pair(-nCost, make_pair(ny, nx)));
        dist[ny][nx] = nCost;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int c = 1;
  while(1){
    cin >> N;
    memset(arr, 0, sizeof(arr));
    memset(dist, 0, sizeof(dist));
    if(N == 0) break;
    
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        dist[i][j] = 1e9;
      }
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> arr[i][j];
      }
    }

    dijakstra();

    cout << "Problem " << c++ << ": " << dist[N-1][N-1] << '\n';
  }
}