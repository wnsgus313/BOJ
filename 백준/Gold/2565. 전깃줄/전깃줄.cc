#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, r;
int cache[101];
vector<pair<int, int> > v;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> l >> r;
    v.push_back(make_pair(l, r));
  }

  sort(v.begin(), v.end());

  for(int i=0; i<n; i++){
    cache[i] = 1;
    for(int j=0; j<i; j++){
      if(v[i].second > v[j].second){
        cache[i] = max(cache[i], cache[j] + 1);
      }
    }
  }
  cout << n - *max_element(cache, cache+n);
}