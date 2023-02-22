#include <iostream>
#include <queue>

using namespace std;
#define max 1001

int arr[max][max];
bool visited[max];

int N, M, V, i, j, v1, v2, t;
queue<int> q;
void dfs(int s)
{   
    cout << s << ' ';
    visited[s] = true;
    for(int i=1; i<=N; i++){
        if(arr[s][i] && !visited[i]){
            dfs(i);
        }
    }
}
void bfs(int s)
{
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        t = q.front();
        q.pop();
        cout << t << ' ';
        for(i=1; i<=N; i++){
            if(arr[t][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    for(i=0; i<M; i++){
        cin >> v1 >> v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }

    dfs(V);
    for(i=1; i<=N; i++)
        visited[i] = false;
    cout << '\n';
    bfs(V);
}   