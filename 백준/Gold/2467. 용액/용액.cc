#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int N, res=INT_MAX, l, r, resL, resR;
vector<int> v;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> N;
  v.resize(N);

  for(int i=0; i<N; i++){
    cin >> v[i];
  }

  r = N-1;
  while(l < r){
    int sum = v[l] + v[r];
    if(abs(sum) < res){
      res = abs(sum);
      resL = v[l];
      resR = v[r];
    }
    if(sum > 0){
      r--;
    }
    else l++;
  }
  cout << resL << ' ' << resR;
}