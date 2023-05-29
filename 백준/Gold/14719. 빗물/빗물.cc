// 1시간 20분
#include <iostream>
#include <algorithm>
using namespace std;

int H, W, res;
int arr[500][500];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> H >> W;
  for(int i=0; i<W; i++){
    int h = 0;
    cin >> h;
    for(int j=0; j<h; j++){
      arr[j][i] = 1;
    }
  }

  for(int i=0; i<H; i++){
    // 블록이 있으면 시작, 다음에 블록이 있을 때까지 더하기
    int start = 0; // 1이면 sum을 시작
    int sum = 0;
    for(int j=0; j<W; j++){
      if(arr[i][j] == 0 && start){
        sum++;
        continue;
      }

      // 이전 블록이랑 현재 블록이 채워져 있으면 reset
      if(j>0 && arr[i][j-1] == 1 && arr[i][j] == 1){
        sum = 0;
        start = 1;
      }
      // 현재 블록이 채워져 있고 시작이 안되어 있으면 시작
      else if(arr[i][j] == 1 && !start){
        start = 1;
      }
      // 현재 블록이 채워져 있고 시작되어 있으면 종료
      else if(arr[i][j] == 1 && start){
        start = 1;
        res += sum;
        sum = 0;
      }
    }
  }

  cout << res << "\n";
}