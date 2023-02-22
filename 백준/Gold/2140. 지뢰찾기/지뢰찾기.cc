#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;
char map[102][102];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 남에서 반시계
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int N, i, j, k, res, d, x=1, y=1;

void search(int flag) {
  int mine = map[y][x] - '0';
  for(k=0; k<3; k++){
    int ty = y + dy[(flag - k + 8) % 8];
    int tx = x + dx[(flag - k + 8) % 8];
    if((1>tx || tx>N || 1>ty || ty>N)) continue;
    if(map[ty][tx] == '*') {
      mine--;
      continue;
    }
    if(map[ty][tx] == '#' && mine) {
      mine--;
      map[ty][tx] = '*';
    }
    else if(map[ty][tx] == '#' && !mine){
      map[ty][tx] = 'x';
    }
  } 
}

void greedy()
{
  for(auto n : {N-1, N-1, N-1, N-2}) {
    for(j=1; j<=n; j++){
      search((d*2+3) % 8);  
      x += dx[2*d];
      y += dy[2*d];
    }
    d = (d+1) % 4;
  }
}

int main()
{
  scanf("%d", &N);
  for(i=1; i<=N; i++){
    for(j=1; j<=N; j++){
      scanf(" %c", &map[i][j]);
    }
  }

  greedy();
  for(i=1; i<=N; i++){
    for(j=1; j<=N; j++){
      if(map[i][j] == '*' || map[i][j] =='#') res++;
    }
  }

  printf("%d\n", res);
}        