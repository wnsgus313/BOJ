#include <iostream>
#include <vector>

using namespace std;

typedef struct Arr{
  int num, sNum, k, scent; // 냄새가 있으면 scent = 1
} Arr;

typedef struct Shark{
  int y, x, death, num, d; // 상어 죽으면 death = 1
  int priorityD[4][4];
} Shark;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, k, res;
vector<Shark> shark;
Arr arr[20][20];

bool liveOne()
{
  int ret = true;
  for(int i=0; i<M; i++){
    if(shark[i].death == 0 && i != 0) ret = false;
  }

  return ret;
}

bool inRange(int y, int x){
  return 0 <= y && y < N && 0 <= x && x < N;
}

void makeScent(){
  for(int i=0; i<M; i++){
    if(shark[i].death == 1) continue;

    int y = shark[i].y;
    int x = shark[i].x;

    arr[y][x].scent = 1;
    arr[y][x].sNum = i+1;
    arr[y][x].k = k;
  }
}
void removeScent(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(arr[i][j].scent == 1 && arr[i][j].k > 0){
        arr[i][j].k--;
        if(arr[i][j].k == 0){
          arr[i][j].scent = 0;
          arr[i][j].sNum = 0;
        }
      }
    }
  }
}

void go(){
  while(1){
    if(res > 1000){
      cout << -1;
      break;
    }

    if(liveOne()){
      cout << res;
      break;
    }
    res++;

    for(int i=0; i<M; i++){
      if(shark[i].death) continue; // 상어 죽었으면 무시
      
      int y = shark[i].y;
      int x = shark[i].x;

      // 냄새가 없을 때
      int flag = 0;
      for(int j=0; j<4; j++){
        int nd = shark[i].priorityD[shark[i].d][j] % 4;
        int ny = y + dy[nd];
        int nx = x + dx[nd];

        if(inRange(ny, nx) && arr[ny][nx].scent == 0){
          flag = 1;
          if(arr[ny][nx].num != 0 && arr[ny][nx].num < i+1){
            arr[y][x].num = 0;
            shark[i].death = 1;
            break;
          }

          arr[y][x].num = 0;
          shark[i].y = ny;
          shark[i].x = nx;
          shark[i].d = nd;
          arr[ny][nx].num = i+1;

          break;
        }
      }
        
      if(flag) continue;

      // 냄새가 있을 때
      for(int j=0; j<4; j++){
        int nd = shark[i].priorityD[shark[i].d][j] % 4;
        int ny = shark[i].y + dy[nd];
        int nx = shark[i].x + dx[nd];

        if(inRange(ny, nx) && arr[ny][nx].scent == 1 && arr[ny][nx].sNum == i+1){
          arr[y][x].num = 0;
          shark[i].y = ny;
          shark[i].x = nx;
          shark[i].d = nd;
          arr[ny][nx].num = i+1;
          break;
        }
      }
    }

    removeScent();
    makeScent();
  }
}

int main()
{
  cin >> N >> M >> k;
  shark.resize(M);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j].num;

      if(arr[i][j].num > 0){
        shark[arr[i][j].num - 1].y = i;
        shark[arr[i][j].num - 1].x = j;      
      }
    }
  }

  // 상어 정보
  for(int i=0; i<M; i++){
    cin >> shark[i].d;
    shark[i].num = i + 1;
    shark[i].d--;
  }

  for(int i=0; i<M; i++){
    int a = 0;

    for(int j=0; j<4; j++){
      for(int k=0; k<4; k++){
        cin >> shark[i].priorityD[j][k];
        shark[i].priorityD[j][k]--;
      }
    }
  }

  makeScent();
  go();

  return 0;
}
