// 23분
#include <iostream>
#define endl "\n"

using namespace std;

bool IsPelindrome(int n){
  string s = to_string(n);

  for(int i=0; i<s.length()/2; i++){
    if(s[i] != s[s.length()-1-i]) return 0; // 다르면 false 반환
  }

  return 1;
}

int cache[1001];
int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T;

  cin>>T;
  
  // 숫자가 펠린드롬인지 확인
  for(int n=1; n*n<=1000; n++){
    // 수와 제곱이 펠린드롬이면 1
    if(IsPelindrome(n) && IsPelindrome(n*n)){
      cache[n*n] = 1;
    }
  }

  for(test_case = 1; test_case <= T; ++test_case)
  {
    int res = 0, l, r;

    cin >> l >> r;

    for(int i=l; i<=r; i++){
      if(cache[i]) res++;
    }
    cout << "#" << test_case << ' ' << res << endl;
  }

  return 0;
}