// 50분
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

deque<int> order;
vector<vector<int> > r; // a -> b
vector<vector<int> > l; // b -> a
int memo[100][100]; // 가장 작은 값이 들어있는 dp
vector<pair<int, int> > matrix; // 행 렬

int GetRes(int l, int r)
{
  // l == r이면 0
  if(l == r) return 0;

  // l+1 == m이면 두 행렬 곱 개수
  else if(l+1 == r){
    return matrix[l].first * matrix[l].second * matrix[r].second;
  }

  int& ret = memo[l][r];
  // 이미 계산했으면 반환
  if(ret != 1e9) return ret;
  
  for(int i=l; i<r; i++){
    int temp = GetRes(l, i) + GetRes(i+1, r) + matrix[l].first * matrix[i].second * matrix[r].second;
    ret = min(ret, temp);
  }

  return ret;
}

void dfs(int start, int flag)
{
  if(flag == 0 && r[start].size() == 1){
    // push_back
    order.push_back(start);
    order.push_back(r[start][0]);
    dfs(r[start][0], 0);
  }

  if(flag == 1 && l[start].size() == 1){
    // push_front
    order.push_front(start);
    order.push_front(l[start][0]);
    dfs(l[start][0], 1);
  }
}

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

    int arr[N+2][N+2][3]; // 물질, 행, 열
    memset(arr, 0, sizeof(arr));

    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        cin >> arr[i][j][0];
      }
    }

    vector<pair<int, int> > v; // 행, 열

    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        if(arr[i][j][0] == 0) continue; // 화학 물질이 없으면 넘기기

        // 왼쪽 오른쪽이 둘다 0이면 행과 열 크기는 1
        if(arr[i-1][j][0] == 0 && arr[i][j-1][0] == 0) arr[i][j][1] = arr[i][j][2] = 1;
        // 아래, 왼쪽 모두 화학 물질이 있으면
        else if(arr[i-1][j][0] != 0 && arr[i][j-1][0] != 0){
          arr[i][j][1] = arr[i-1][j][1] + 1; // 아래에서 행 추가
          arr[i][j][2] = arr[i][j-1][2] + 1; // 옆에서 열 추가
        }
        // 아래에만 화학 물질이 있으면
        else if(arr[i-1][j][0] != 0){
          arr[i][j][1] = arr[i-1][j][1] + 1; // 행은 추가
          arr[i][j][2] = arr[i-1][j][2]; // 열은 그대로
        }
        // 왼쪽에만 화학 물질이 있으면
        else if(arr[i][j-1][0] != 0){
          arr[i][j][1] = arr[i][j-1][1]; // 행은 그대로
          arr[i][j][2] = arr[i][j-1][2] + 1; // 열은 추가
        }

        // 위, 오른쪽이 0 이면 마지막 위치
        if(arr[i+1][j][0] == 0 && arr[i][j+1][0] == 0){
          v.push_back(make_pair(arr[i][j][1], arr[i][j][2]));
        }
      }
    }
    
    r.clear();
    l.clear();

    r.resize(N + 1);
    l.resize(N + 1);

    for(int i=0; i<v.size(); i++){
      r[v[i].first].push_back(v[i].second);
      l[v[i].second].push_back(v[i].first);
    }

    dfs(v[0].first, 0); // 왼쪽으로 추가
    dfs(v[0].first, 1); // 오른쪽으로 추가

    matrix.clear(); // 정돈된 행렬
    while(!order.empty()){
      int a = order.front();
      order.pop_front();
      int b = order.front();
      order.pop_front();

      matrix.push_back(make_pair(a, b));
    }
    
    // dp 가장 큰 값 초기화
    for(int i=0; i<100; i++){
      for(int j=0; j<100; j++){
        memo[i][j] = 1e9;
      }
    }
    int res = GetRes(0, matrix.size()-1);

    cout << "#" << test_case << ' ' << res << endl;
  }

  return 0;
}