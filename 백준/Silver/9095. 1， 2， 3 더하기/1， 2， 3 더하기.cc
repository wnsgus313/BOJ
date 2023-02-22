#include <iostream>
#define M 11

using namespace std;
int n, i, v;
int arr[M];

int main() {
  cin >> n;

  arr[1]=1; arr[2]=2; arr[3]=4;
  for(i=4; i<M; i++){
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }

  for(i=0; i<n; i++){
    cin >> v;
    cout << arr[v] << endl;
  }

  return 0;
}