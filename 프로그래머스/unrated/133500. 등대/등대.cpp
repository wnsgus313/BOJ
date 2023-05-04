#include <string>
#include <vector>

using namespace std;

int answer;
vector<vector<int> > adj;
vector<int> visited;
vector<int> on;
void dfs(int node, int parent)
{
    visited[node] = 1;

    for(int i=0; i<adj[node].size(); i++){
        int nNode = adj[node][i];
        
        if(visited[nNode]) continue; // 이미 방문했으면 무시
        
        dfs(nNode, node);
    }
     // 부모, 자식 둘 다 등대가 안켜져 있으면 부모 등대 켜기
    if(!on[node] && !on[parent] && parent != 0) {
        on[parent] = 1;
        answer++;
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    adj.resize(n+1);
    visited.resize(n+1);
    fill(on.begin(), on.end(), 0);
    on.resize(n+1);
    fill(on.begin(), on.end(), 0);
    
    for(int i=0; i<lighthouse.size(); i++){
        adj[lighthouse[i][0]].push_back(lighthouse[i][1]);
        adj[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    
    // 등대 1번을 root라고 생각하고 시작
    dfs(1, 0);
    
    return answer;
}