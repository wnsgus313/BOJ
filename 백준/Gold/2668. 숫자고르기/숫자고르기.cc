// 54분
/*
  사이클을 합친 값 반환
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> pq; // 뽑힌 정수
int arr[2][102]; // idx, 숫자
int visited[102];
vector<int> v;
vector<int> res;
void Find(int start, int from){
  // 사이클이면 다 집어 넣기
  if(start == from){
    for(auto au : v){
      pq.push(-au);
    }
    res = v;
  }
  // 이미 방문했으면 종료
  if(visited[from]) return;
  
  v.push_back(from);
  visited[from] = 1;
  Find(start, arr[1][from]);
  v.pop_back();
  visited[from] = 0;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N;

  cin >> N;
  for(int i=1; i<=N; i++){
    arr[0][i] = i;
    cin >> arr[1][i];

    // 위 아래가 같으면 깍두기
    if(i == arr[1][i]) {
      visited[i] = 1;
      pq.push(-i);
    }
  }

  // 깍두기를 제외하고 사이클이 이뤄지면 가능
  for(int i=1; i<=N; i++){
    for(auto au : res){
      visited[au] = 1;
    }
    res.clear();
    if(visited[i] == 1) continue;

    v.push_back(i);
    visited[i] = 0;
    Find(i, arr[1][i]);
    visited[i] = 0;
    v.pop_back();
  }

  cout << pq.size() << '\n';
  while(!pq.empty()){
    cout << -pq.top() << '\n';
    pq.pop();
  }
}