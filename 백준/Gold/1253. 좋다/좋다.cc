// 투 포인터 사용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;
int N, res;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  A.resize(N);

  for(int i=0; i<N; i++){
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  for(int i=0; i<N; i++){
    int find = A[i]; // 찾는 값
    
    int l = 0, r = N-1;

    while(l < r){
      int sum = A[l] + A[r];
      // 두개 모두 자기 자신이 아닐때 찾으면 종료
      if(find == sum){
        if(l != i && r != i){
          res++;
          break;
        }
        else if(l == i) l++;
        else if(r == i) r--;
      }
      else if(find < sum){
        r--;
      }
      else{
        l++;
      }
    }
  }

  cout << res << '\n';
}