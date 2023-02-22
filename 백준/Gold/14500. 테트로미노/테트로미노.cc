#include <iostream>
#include <algorithm>
using namespace std;
#define S 501
int map[S][S];
bool visit[S][S];

int i, j, n, m, maxV;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int dfs(int y, int x, int cnt)
{
    if(cnt == 5) return 0;
    int v = 0;
    for(int t=0; t<4; t++){
        int ny = y + dy[t];
        int nx = x + dx[t];
        if(nx>=0 && nx<m && ny>=0 && ny<n){
            if(!visit[ny][nx]){
                visit[ny][nx] = true;
                v = max(v, dfs(ny, nx, cnt+1) + map[y][x]);
                visit[ny][nx] = false;
            }
        }
    }
    return v;
}
int elcase(int y, int x)
{
    int v = 0;
    if(y>=1 && x>=1 && x<m-1)
        v = max(v, map[y][x] + map[y-1][x] + map[y][x-1] + map[y][x+1]);
    if(y<n-1 && x>=1 && x<m-1)
        v = max(v, map[y][x] + map[y+1][x] + map[y][x-1] + map[y][x+1]);
    if(y<n-1 && y>=1 && x<m-1)
        v = max(v, map[y][x] + map[y+1][x] + map[y-1][x] + map[y][x+1]);
    if(y<n-1 && y>=1 && x>=1)
        v = max(v, map[y][x] + map[y+1][x] + map[y-1][x] + map[y][x-1]);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int v = 0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            visit[i][j] = true;
            v = max(v, elcase(i, j));
            v = max(v, dfs(i, j, 1));
            visit[i][j] = false;
        }
    }
    cout << v;
}