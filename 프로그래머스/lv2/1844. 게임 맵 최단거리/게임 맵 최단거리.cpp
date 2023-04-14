#include <vector>
#include <queue>

using namespace std;

int n, m;
int visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < m;
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    n = maps.size();
    m = maps[0].size();

    queue<pair<int, pair<int, int> > > q; // cost, y, x
    q.push({1, {0, 0}});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int y = q.front().second.first;
        int x = q.front().second.second;
        int cost = q.front().first;
        q.pop();
                
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(!InRange(ny, nx) || visited[ny][nx] || !maps[ny][nx]) continue;
            if(ny == n-1 && nx == m-1) return cost+1;

            visited[ny][nx] = 1;
            q.push({cost + 1, {ny, nx}});
        }
    }
    
    
    return answer;
}