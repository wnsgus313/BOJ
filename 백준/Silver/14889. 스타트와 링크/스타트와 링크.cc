#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[21][21];
bool visited[21];
int N, res = 10000000;

void dfs(int x, int cnt){
  if(cnt == N/2){
    int start = 0, link = 0;

    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        if(visited[i] && visited[j]){
          start += arr[i][j] + arr[j][i];
        }
        else if(!visited[i] && !visited[j]){
          link += arr[i][j] + arr[j][i];
        }
      }
    }

    res = min(res, abs(start - link));
    return ;
  }

  for(int i=x; i<N; i++){
    if(!visited[i]){
      visited[i] = true;
      dfs(i+1, cnt+1);
      visited[i] = false;
    }
  }
}

int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  dfs(0, 0);
  printf("%d", res);
}