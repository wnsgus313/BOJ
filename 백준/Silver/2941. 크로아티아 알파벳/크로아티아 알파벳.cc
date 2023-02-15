#include <iostream>
#include <string>
using namespace std;

string s;
string lst[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main()
{
  cin >> s;

  for(int i=0; i<8; i++){
    while(s.find(lst[i]) != -1){
      s.replace(s.find(lst[i]), lst[i].length(), "a");
    }
  }
  cout << s.length();
}