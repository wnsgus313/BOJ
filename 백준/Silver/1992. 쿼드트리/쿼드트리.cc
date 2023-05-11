#include <iostream>
using namespace std;

int N;
char arr[64][64];

void conquer(int y, int x, int n){
  int cnt = 0;

  for(int i=y; i<y+n; i++){
    for(int j=x; j<x+n; j++){
      if(arr[i][j] == '1'){
        cnt++;
      }
    }
  }
  
  if(!cnt) cout << 0;
  else if(cnt == n*n) cout << 1;
  else{
    cout << '(';
    conquer(y, x, n/2);
    conquer(y, x+n/2, n/2);
    conquer(y+n/2, x, n/2);
    conquer(y+n/2, x+n/2, n/2);
    cout << ')';
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j];
    }
  }

  conquer(0, 0, N);
}