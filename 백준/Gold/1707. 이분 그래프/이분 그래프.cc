#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 20001
vector<int> arr[MAX];
int color[MAX]; // 레드=1, 블루=-1
int K, V, E, n1, n2, flag;

void dfs(int node, int flag)
{
    color[node] = flag;
    for(auto i=0; i<arr[node].size(); i++){
        if(!color[arr[node][i]])
            dfs(arr[node][i], flag*-1);
    }
}
bool check(void){
    for(int i=1; i<=V; i++){
        for(auto j=0; j<arr[i].size(); j++){
            if(color[i] == color[arr[i][j]])
                return false;
        }
    }
    return true;    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K;

    while(K--){
        for(int i=1; i<MAX; i++)
            arr[i].clear();
        memset(color, 0, sizeof(color));

        cin >> V >> E;
        for(int i=0; i<E; i++){
            cin >> n1 >> n2;
            arr[n1].push_back(n2);
            arr[n2].push_back(n1);
        }
        for(int i=1; i<=V; i++){
            if(color[i] == 0){
                dfs(i, 1);
            }
        }

        if(check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}