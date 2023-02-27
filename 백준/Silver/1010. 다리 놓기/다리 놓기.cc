#include <iostream>

using namespace std;

int N, M, T, res;
long long cache[31];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> T;

  while(T--){
    cin >> N >> M;
    res = 1;
    for(int i=1; i<=N; i++){
      res *= M - i + 1;
      res /= i;
    }
    cout << res << '\n';
  }
}