#include <iostream>
#include <string>
using namespace std;

int A, B;
string r;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> A >> B;
  if(A > B)
    r = '>';
  else if(A < B)
    r = '<';
  else if(A == B)
    r = "==";
  
  cout << r;
}