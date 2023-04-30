// 37분
#include <algorithm>
#include <vector>

using namespace std;

int visited[100];
int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<int> v;
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue; // 이미 열려 있으면 다시
        
        // 연 상자일 때까지 반복
        int idx = i;
        int cnt = 0; // 개수 세기
        while(!visited[idx]){
            visited[idx] = 1; // 방문 처리
            idx = cards[idx] - 1; // 다음 idx로 변경
            cnt++; // 개수 증가
        }
        v.push_back(cnt);
    }
    
    sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬
    
    if(v.size() == 1) return 0; // 상자가 1개만 만들어지면 0 리턴
    
    answer = v[0] * v[1]; 
    
    return answer;
}