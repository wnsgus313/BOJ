#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
int i, cnt, dup;
string res;
map<char, int> m;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> s;
  for(i=0; i<s.length(); i++){
    s[i] = (char)toupper(s[i]);
    if(m.find((s[i])) != m.end()){
      m[s[i]] += 1;
    }
    else{
      m.insert(make_pair((char)toupper(s[i]), 1));
    }
  }
  for(auto iter=m.begin(); iter!=m.end(); iter++){
    if(cnt == iter->second) res = "?";
    if(cnt < iter->second){
      cnt = iter->second;
      res = iter->first;
    }
  }

  cout << res[0];
}