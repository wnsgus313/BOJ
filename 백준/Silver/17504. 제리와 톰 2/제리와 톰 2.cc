#include <iostream>
#include <queue>
using namespace std;

int N, first;
long long denom, numer=1, t, r, a, b;

deque<int> integer;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;

  integer.resize(N);
  for(int i=0; i<N; i++){
    cin >> integer[i];
  }

  denom = integer.back();
  integer.pop_back();

  while(!integer.empty()){
    first = integer.back();
    integer.pop_back();

    t = denom;
    denom = first * denom + numer;
    numer = t;
  }
  
  numer = denom - numer;

  a = denom, b = numer;
  while(1){
    r = a % b;
    if(r == 0){
      break;
    }
    a = b;
    b = r;
  }
  cout << numer / b << ' ' << denom / b;
}