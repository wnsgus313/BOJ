// 54분
/*
  사이클을 합친 값 반환
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

priority_queue<int> pq; // 뽑힌 정수
int arr[102]; // idx, 숫자
int visited[102];
vector<int> v;
void Find(int start, int from){
  // 사이클이면 다 집어 넣기
  if(start == from){
    pq.push(-start);
  }
  // 이미 방문했으면 종료
  if(visited[from]) return;
  
  v.push_back(from);
  visited[from] = 1;
  Find(start, arr[from]);
  v.pop_back();
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N;

  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> arr[i];
  }

  // 깍두기를 제외하고 사이클이 이뤄지면 가능
  for(int i=1; i<=N; i++){
    memset(visited, 0, sizeof(visited));
    
    v.push_back(i);
    visited[i] = 1;
    Find(i, arr[i]);
    v.pop_back();
  }

  cout << pq.size() << '\n';
  while(!pq.empty()){
    cout << -pq.top() << '\n';
    pq.pop();
  }
}