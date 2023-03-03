#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, a, b, S, cnt[2], l, r, flag;
int check[10001];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> T;
  while(T--){
    cin >> a >> b >> S;

    cnt[0] = 0, cnt[1] = 0, l = 0, r = 1, flag = 0;
    memset(check, 0, sizeof(check));

    if(a < b) {
      flag = 1;
      swap(a, b);
    };

    cnt[l] = S / a;
    S %= a;
    cnt[r] = S / b;
    S %= b;
    
    while(S > 0 && cnt[l] > 0){
      --cnt[l];
      S += a;

      cnt[r] += S / b;
      S %= b;

      if(check[S]) break;
      check[S] = 1;
    }

    if(flag) swap(l, r);
    
    if(S) cout << "Impossible\n"; 
    else cout << cnt[l] << ' ' << cnt[r] << '\n';
  }
}