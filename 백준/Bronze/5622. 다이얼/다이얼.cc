#include <iostream>
#include <string>

using namespace std;

string s;
int t;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> s;
  for(int i=0; i<s.length(); i++){
    char c = s[i];

    if(c - 'C' <= 0) t += 3;
    else if(c - 'F' <= 0) t += 4;
    else if(c - 'I' <= 0) t += 5;
    else if(c - 'L' <= 0) t += 6;
    else if(c - 'O' <= 0) t += 7;
    else if(c - 'S' <= 0) t += 8;
    else if(c - 'V' <= 0) t += 9;
    else if(c - 'Z' <= 0) t += 10;
  }

  cout << t;
}