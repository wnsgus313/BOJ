// 18분
#include <iostream>
#include <vector>
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
    int N = 0, a = 0, b = 0, P = 0;
    vector<pair<int, int> > v;
    vector<int> C;
    int res[5001] = {0}; // 같은 메모리를 쓸 때 초기화를 안했으면 이전 값이 계속 사용됨

    cin >> N;
    for(int i=0; i<N; i++){
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }

    cin >> P;
    C.resize(P);

    for(int i=0; i<P; i++){
      cin >> C[i];
    }

    // 각 위치에 1씩 추가
    for(int i=0; i<N; i++){
      int Ai = v[i].first;
      int Bi = v[i].second;

      // [Ai, Bi] 노선 추가
      for(int j=Ai; j<=Bi; j++){
        res[j]++;
      }
    }

    cout << "#" << test_case << ' ';
    for(int i=0; i<P; i++){
      cout << res[C[i]] << ' '; // Ci 정거장 노선 개수 출력
    }
    cout << endl;
  }

  return 0;
}