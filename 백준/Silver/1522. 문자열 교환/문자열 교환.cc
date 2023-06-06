#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int aN, res = 1e9; // a 개수
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s;

  for(int i=0; i<s.length(); i++){
    if(s[i] == 'a') aN++;
  }
  if(aN == 0) {
    cout << 0;
    return 0;
  }
  for(int i=0; i<s.length(); i++){
    int bN = 0; // b의 개수
    int l = 0; // 길이
    for(int j=i; ; j=(j+1)%s.length()){
      l++;
      if(s[j] == 'b') bN++;
      if(l == aN){
        res = min(res, bN);
        break;
      }
    }
  }

  cout << res << '\n';
}