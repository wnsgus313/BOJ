#include <iostream>
using namespace std;

int N, M;
int arr[9];

void go(int cnt){
  if(cnt == M){
    for(int i=0; i<M; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return;
  }

  for(int i=1; i<=N; i++){
    if(cnt != 0 && i < arr[cnt-1]) continue;
    arr[cnt] = i;
    go(cnt + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;
  go(0);
}