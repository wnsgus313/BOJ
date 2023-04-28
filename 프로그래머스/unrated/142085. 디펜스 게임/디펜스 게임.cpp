// 41분
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = k;
    int s = enemy.size(); // 적군의 길이
    priority_queue<int> pq;
    
    // k번까지 min heap에 넣기
    for(int i=0; i<k; i++){
        pq.push(-enemy[i]);
    }

    // 한개씩 빼면서 비교
    while(1){
        // 적군의 길이가 현재 참조할 enemy 순서보다 작거나 같으면 정답 변경 후 종료
        if(answer >= s) {
            answer = s; // 정답이 초과되면 enemy의 길이로 변경
            break;
        };
        
        pq.push(-enemy[answer]); // 새로운 적을 넣기
        int e = -pq.top(); // 가장 적은 적군의 수
        pq.pop();

        // 싸울 수 있으면 추가 
        if(n - e >= 0){
            answer++; // 값 증가
            
            n -= e; // 싸운 적군만큼 차감
        }
        else{
            break;
        }
    }
        
    return answer;
}