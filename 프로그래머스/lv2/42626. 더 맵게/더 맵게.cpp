#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n = scoville.size();
    
    priority_queue<int> pq; // Max Heap
    for(int i=0; i<n; i++){
        pq.push(-scoville[i]); // Min Heap과 같은 효과
    }
        
    while(!pq.empty() && -pq.top() < K){
        int l = -pq.top();
        pq.pop();
        if(pq.empty()) {
            pq.push(-l);
            break;
        };
        
        int r = -pq.top();
        pq.pop();
        
        pq.push(-(l+2*r));
        answer++;
    }
    
    if(!pq.empty() && -pq.top() < K) answer = -1;
    
    
    return answer;
}