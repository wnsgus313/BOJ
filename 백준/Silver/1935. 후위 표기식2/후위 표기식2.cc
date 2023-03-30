#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
double l, r;
string str;
stack<double> s;
int num[26];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> str;

  for(int i=0; i<N; i++){
    cin >> num[i];
  }

  for(int i=0; i<str.length(); i++){
    if(str[i] < 'A' || 'Z' < str[i]){
      char op = str[i];
      double v = 0;

      r = s.top(); s.pop();
      l = s.top(); s.pop();

      if(op == '+')
        v = l + r;
      else if(op == '-')
        v = l - r;
      else if(op == '*')
        v = l * r;
      else if(op == '/')
        v = l / r;
      s.push(v);
    }
    else{
      s.push(num[str[i]-'A']);
    }
  }

  cout.precision(2);
  cout << fixed << s.top();
}