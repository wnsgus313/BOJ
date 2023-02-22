#include <iostream>
using namespace std;

int map[999][999];
int N, F, i, j, x, y, direction, n2, resX, resY;
int dx[4] = {0, 1, 0, -1}; // S, E, N, W
int dy[4] = {1, 0, -1, 0};
int d[4];

void go()
{
  y += dy[direction];
  x += dx[direction];

  if(n2 == F) {
    resX = x+1;
    resY = y+1;
  }
  map[y][x] = n2--;
};

int main()
{
  scanf("%d %d", &N, &F);
  
  y = -1; n2 = N * N;

  d[0] = N; d[1] = N-1; d[2] = N-1; d[3] = N-2;

  for(i=0; i<(N+1)/2; i++){
    for(j=0; j<d[0]; j++){
      go();
    }
    direction = (direction + 1) % 4;
    for(j=0; j<d[1]; j++){
      go();
    }
    direction = (direction + 1) % 4;
    for(j=0; j<d[2]; j++){
      go();
    }
    direction = (direction + 1) % 4;
    for(j=0; j<d[3]; j++){
      go();
    }
    direction = (direction + 1) % 4;
    
    for(j=0; j<4; j++)
      d[j] -= 2;
  }

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      cout << map[i][j] << ' '; 
    }
    cout << '\n';
  }
  cout << resY << ' ' << resX << '\n';
}