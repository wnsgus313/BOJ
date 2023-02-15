#include <iostream>
#include <map>
using namespace std;

string s[101];
map<char, int> m;
int n, i, j, res;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(i=0; i<n; i++){
    cin >> s[i];
  }

  for(i=0; i<n; i++){
    int flag = 1;
    m.clear();

    m.insert(make_pair(s[i][0], 1));
    for(j=1; j<s[i].length(); j++){
      while(s[i][j] == s[i][j-1]){
        j++;
      }
      if(m.find(s[i][j]) != m.end()){
        flag = 0;
        break;
      }
      else{
        m.insert(make_pair(s[i][j], 1));
      }
    }
    if(flag) res++;
  }
  
  cout << res;
}