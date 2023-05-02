#include <iostream>
#include <algorithm>
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
    int res = 0, A, B, C, D;
    pair<int, int> l, r;
    // 먼저 켜진 전구 l, 나중에 켜진 전구 r 구분(A > C)
    // r.start > l.finish면 같이 켜진 시간 0
    // 그 외의 경우고 l.finish >= r.finish인 경우에는 r.finish - r.start
    // 그 외의 경우 l.finish - r.start

    cin >> A >> B >> C >> D;
    l = make_pair(A, B);
    r = make_pair(C, D);

    if(A > C) swap(l, r); 

    if(r.first > l.second) res = 0;
    else if(l.second >= r.second) res = r.second - r.first;
    else res = l.second - r.first;

    cout << "#" << test_case << ' ' << res << endl;
  }

  return 0;
}