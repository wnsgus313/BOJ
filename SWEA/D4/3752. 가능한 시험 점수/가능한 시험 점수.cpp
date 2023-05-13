// 1시간
#include <iostream>
#include <vector>
#include <iomanip>
#define endl "\n"

using namespace std;

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T;

  cin>>T;

  for(test_case = 1; test_case <= T; ++test_case)
  {
    int N;

    cin >> N;

    vector<int> arr(N);
    int memo[10001] = {0};

    for(int i=0; i<N; i++){
      cin >> arr[i];
    }
    
    memo[0] = 1; // 아무것도 선택 안했을 때
    int high = 0; // 가장 높은 수 저장
    for(int i=0; i<N; i++){
      high += arr[i];

      //(*) 0부터 시작하면 중복될 수 있음
      for(int j=high; j>=0; j--){
        if(memo[j]){
          memo[j+arr[i]] = 1;
        }
      }
    }

    int res = 0;
    for(int i=0; i<=high; i++){
      if(memo[i]) res++;
    }

    cout << "#" << test_case << ' ' << res << endl;
  }

  return 0;
}