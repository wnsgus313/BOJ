#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char board[51][51];
int c[2][51][51];
int N, M, res = 100;
char color[2] = {'W', 'B'};
bool flag[2] = {0, 1};
string s;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> s;

    for(int j=0; j<s.length(); j++){
      board[i][j] = s[j];
    }
  }

  for(int i=0; i<N-7; i++){
    for(int j=0; j<M-7; j++){
      for(int n=i; n<i+8; n++){
        for(int m=j; m<j+8; m++){
          if(board[n][m] != color[flag[0]]){
            c[0][i][j]++;
          }
          
          if(board[n][m] != color[flag[1]]){
            c[1][i][j]++;
          }
          flag[0] = !flag[0];
          flag[1] = !flag[1];
        }
        flag[0] = !flag[0];
        flag[1] = !flag[1];
      }
    }
  }

  for(int i=0; i<N-7; i++){
    for(int j=0; j<M-7; j++){
      res = min(res, c[0][i][j]);
      res = min(res, c[1][i][j]);
    }
  }

  cout << res;
}