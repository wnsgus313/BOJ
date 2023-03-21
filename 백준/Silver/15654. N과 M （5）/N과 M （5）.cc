#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[8];
int visited[8];
int N, M;
vector<int> lst;

void dfs(int idx, int cnt, vector<int> v){
  if(cnt == M) {
    for(int i=0; i<v.size(); i++){
      cout << v[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=0; i<N; i++){
    if(visited[i] || i == idx) continue;

    visited[idx] = 1;
    v.push_back(arr[i]);
    dfs(i, cnt + 1, v);
    visited[idx] = 0;
    v.pop_back();
  }

  return;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }
  sort(arr, arr + N);

  for(int i=0; i<N; i++){
    lst.push_back(arr[i]);
    dfs(i, 1, lst);
    lst.pop_back();
  }
}