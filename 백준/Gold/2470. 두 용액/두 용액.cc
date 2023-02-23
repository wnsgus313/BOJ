#include <iostream>
#include <algorithm>
using namespace std;

int N, l, r, ll, rr, sum = 2000000001;
int arr[100001];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr, arr + N);
  r = N-1;

  while(l < r){
    int diff = arr[l] + arr[r];
    if(sum > abs(diff)){
      sum = abs(diff);
      ll = l; rr = r;
    }
    if(diff > 0){
      r--;
    }
    else{
      l++;
    }
  }

  cout << arr[ll] << ' ' << arr[rr];
}