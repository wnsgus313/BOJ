#include <iostream>
#include <algorithm>
using namespace std;

int N, M, t, res = 300001;
int card[101];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;

  for(int i=0; i<N; i++){
    cin >> card[i];
  }

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      for(int k=j+1; k<N; k++){
        t = M - (card[i] + card[j] + card[k]);
        if(t >= 0)
          res = min(res, t);
      }
    }
  }

  cout << M - res;
}