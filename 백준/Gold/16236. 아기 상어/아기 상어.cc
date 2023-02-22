#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int N, arr[20][20], sharkX, sharkY, scale = 2, times, feed;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

class comp{
  public:
    bool operator()(pair<int, int> lhs, pair<int, int> rhs) const{
      if (lhs.second == rhs.second){
        return lhs.first > rhs.first;
      }
      return lhs.second > rhs.second;
    };
};

int find(int x, int y){
  int res = 0, pDis = 0;
  int visited[20][20] = {0, };

  queue<pair<int, pair<int, int> > > q;
  priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;

  q.push(make_pair(0, make_pair(x, y)));

  visited[y][x] = 1;

  while(!q.empty()){
    auto info = q.front();
    int curX = info.second.first, curY = info.second.second;
    q.pop();

    if((0 < arr[curY][curX]) && (arr[curY][curX] < scale)){
      res = info.first;
      arr[curY][curX] = 0;
      sharkX = curX;
      sharkY = curY;
      feed++;
      if(feed == scale){
        feed = 0;
        scale++;
      }
      break;
    }

    for(int i=0; i<4; i++){
      int nextX = curX + dx[i];
      int nextY = curY + dy[i];
      if(!visited[nextY][nextX] && (0 <= nextX && nextX < N) && (0 <= nextY && nextY < N) && (arr[nextY][nextX] <= scale)){
        pq.push(make_pair(nextX, nextY));
        visited[nextY][nextX] = 1;
      }
    }

    if(q.empty()){
      while(!pq.empty()){
        auto pqInfo = pq.top();
        pq.pop();
        q.push(make_pair(info.first + 1, make_pair(pqInfo.first, pqInfo.second)));
      }
    }
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 9){
        sharkY = i;
        sharkX = j;
        arr[i][j] = 0;
      }
    }
  }

  while(1){
    int ret = find(sharkX, sharkY);
    if(ret == 0){
      cout << times;
      break;
    }

    times += ret;
  }
}