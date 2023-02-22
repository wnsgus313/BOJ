#include <iostream>
#include <algorithm>
using namespace std;

int cache[500][500];
int n, v;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      cin >> v;

      int& ret = cache[i][j];
      if(i==0 && j==0) {
        ret = v;
        continue;
      }

      if(j == 0){
        ret = max(cache[i-1][j] + v, ret);
      }
      else if(j == i){
        ret = max(cache[i-1][j-1] + v, ret);
      }
      else{
        ret = max(cache[i-1][j-1] + v, max(cache[i-1][j] + v, ret));
      }
    }
  }

  cout << *max_element(cache[n-1], cache[n-1] + n);
}