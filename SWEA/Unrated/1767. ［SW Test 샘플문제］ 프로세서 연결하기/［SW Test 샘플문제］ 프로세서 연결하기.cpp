#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int arr[12][12];
int res = 999999999;
int cnt, N, maxCnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int, int> > core;

int inRange(int y, int x){
  return (0 <= y && y < N && 0 <= x && x < N);
}

void dfs(int idx, int cnt, int length){
  int y = core[idx].first;
  int x = core[idx].second;

  if(idx > core.size()) return;

  if(cnt == maxCnt){
    res = min(res, length);
  }
  else if(cnt > maxCnt){
    maxCnt = cnt;
    res = length;
  }

  int tArr[12][12] = {0};
  memcpy(tArr, arr, sizeof(arr));

  for(int i=0; i<4; i++){
    int len = 0;
    int ny = y;
    int nx = x;

    while(1){
      ny += dy[i];
      nx += dx[i];
      if(!inRange(ny, nx)) break;
      if(arr[ny][nx]){
        len = 0;
        break;
      }
      arr[ny][nx] = 1;
      len++;
    } 

    if(len > 0){
      dfs(idx+1, cnt+1, length + len);
    }
    memcpy(arr, tArr, sizeof(arr));
  }

  dfs(idx+1, cnt, length);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> cnt;
  
  for(int k=1; k<=cnt; k++){
    cin >> N;
    int out = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> arr[i][j];


        if(arr[i][j] == 1){
          if(i == 0 || i == N-1 || j == 0 || j == N-1) continue;
          core.push_back(make_pair(i, j));
        }
      }
    }

    cout << "#" << k << ' ';
    dfs(0, 0, 0);
    cout << res << '\n';

    memset(arr, 0, sizeof(arr));
    core.clear();
    res = 999999999;
    maxCnt = 0;
    N = 0;
  }
}