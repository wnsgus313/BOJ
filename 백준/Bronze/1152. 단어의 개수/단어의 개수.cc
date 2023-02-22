#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string s;
int res=0, i;

int main()
{
  getline(cin, s);

  for(i=0; i<s.length(); i++){
    if(s[i] != ' '){
      res++;
      break;
    }
  }

  for(; i<s.length(); i++) {
    if(s[i] == ' '){
      if(i+1 == s.length() || s[i+1] == ' ')
        break;
      res++;
    }
  }
  cout << res;
}