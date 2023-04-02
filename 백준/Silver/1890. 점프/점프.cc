#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
long long cache[101][101];
int N;

int main()
{
  cin >> N;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j];
    }
  }

  cache[0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(arr[i][j] == 0) continue;
      int jumpSize = arr[i][j];

      if(j+jumpSize < N){
        cache[i][j+jumpSize] += cache[i][j];
      }
      if(i+jumpSize < N){
        cache[i+jumpSize][j] += cache[i][j];
      }
    }
  }

  cout << cache[N-1][N-1];
}