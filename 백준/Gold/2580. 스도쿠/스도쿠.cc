#include <iostream>
#include <algorithm>

using namespace std;

int N=9;
int board[9][9];

int go(int y, int x){
  if(x >= N) return go(y+1, 0);
  if(y >= N) return 1;
  if(board[y][x]) return go(y, x+1);

  int chk[10] = {0, };
  for(int i=0; i<N; i++) chk[board[y][i]] = chk[board[i][x]] = 1;
  int yy = y / 3 * 3, xx = x / 3 * 3;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      chk[board[yy + i][xx + j]] = 1;
    }
  }

  for(int i=1; i<=N; i++){
    if(!chk[i]){
      board[y][x] = i;
      if (go(y, x+1)) return 1;
      board[y][x] = 0;
    }
  }

  return 0;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cin >> board[i][j];
    }
  }
  go(0, 0);

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}