#include <iostream>
#include <string>
using namespace std;

string s;
int N, start, t, res;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> s;
  start = N - s.length() * 9;

  N = stoi(s);

  if(start <= 0) start = 1;
  for(int i=start; i<N; i++){
    s = to_string(i);
    t = 0;
    for(int j=0; j<s.length(); j++){
      t += s[j] - '0';
    }

    if(N == i + t){
      res = i;
      break;
    }
  }
  cout << res;
}