#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, i, l;
long long res;
vector<int> len;

void binarySearch(long long left, long long right){
  long long count = 0;
  long long mid = (left + right) / 2;

  if(left > right){
    return;
  }
  for(i=0; i<len.size(); i++){
    count += (len[i] / mid);
  }

  if(count < K){
    binarySearch(left, mid-1);
  }
  else if(count >= K){
    if(res < mid)
      res = mid;
    binarySearch(mid+1, right);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  for(i=0; i<N; i++){
    cin >> l;
    len.push_back(l);
  }

  sort(len.begin(), len.end());
  binarySearch(1, len[len.size()-1]);
  cout << res;
}