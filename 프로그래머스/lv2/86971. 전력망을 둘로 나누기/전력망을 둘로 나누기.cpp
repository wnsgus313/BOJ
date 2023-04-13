#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
vector<int> adj[101];
int n;

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    n = wires.size();
    
    // 양방향 길 설정
    for(int i=0; i<n; i++){
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0; i<n; i++){
        int l = wires[i][0];
        int r = wires[i][1];
        int lN = 0;
        set<int> s;
        queue<int> q;
        q.push(l);
        s.insert(l);
        
        // 한 방향의 연결 개수 구하기(왼쪽으로)
        while(!q.empty()){
            int here = q.front();
            q.pop();
            
            for(int i=0; i<adj[here].size(); i++){
                int next = adj[here][i];
                
                // 집합에 없고 오른쪽이 아니면 큐에 넣어서 찾기
                if(s.find(next) == s.end() && next != r){
                    lN++;
                    s.insert(next);
                    q.push(next);
                }
            }
        }
        
        // 오른쪽 방향 개수 = 전체 - 왼쪽 개수 - 1
        answer = min(answer, abs(lN - (n - lN - 1)));
    }
    
    return answer;
}