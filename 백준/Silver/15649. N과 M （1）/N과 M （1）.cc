#include <iostream>
using namespace std;

int N, M;
bool visited[9];
int arr[9];

void go(int cnt){
  if(cnt == M){
    for(int i=0; i<M; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }

  for(int i=1; i<=N; i++){
    if(!visited[i]) {
      visited[i] = true;
      arr[cnt] = i;
      go(cnt + 1);
      visited[i] = false;
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;

  go(0);
}