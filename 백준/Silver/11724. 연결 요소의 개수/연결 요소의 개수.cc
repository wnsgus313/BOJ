#include <iostream>

using namespace std;
#define max 1001

int arr[max][max];
bool visited[max];

int N, M, i, v1, v2, c;
void dfs(int s)
{   
    if(visited[s] == true) {c--; return;}
    visited[s] = true;
    for(int i=1; i<=N; i++){
        if(arr[s][i] && !visited[i]){
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(i=0; i<M; i++){
        cin >> v1 >> v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }

    c = N;
    for(i=1; i<=N; i++){
        dfs(i);
    }
    cout << c;
}   