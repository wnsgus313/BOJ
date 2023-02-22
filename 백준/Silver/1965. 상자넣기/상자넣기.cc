#include <iostream>

using namespace std;

int n, i, k = 0;
int v[1002], s[1001];

int main() {
  cin >> n;

  for(i=1; i<=n; i++)
    cin >> v[i];

  v[0] = -1; s[0] = v[0];

  for(i=1; i<=n; i++){
    if(s[k] < v[i]){
      s[++k] = v[i];
    }
    else{
      s[lower_bound(s, s+k, v[i]) - s] = v[i];
    }
  }

  cout << k << endl;
}