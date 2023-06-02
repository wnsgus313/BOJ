#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int> edge[100001];
int dp[100001][2];
bool visited[100001];
void dfs(int index){
    dp[index][0] = 0;
    dp[index][1] = 1;
    visited[index] = true;
    for(int i = 0; i < edge[index].size(); i++){
        int next_index = edge[index][i];
        if(visited[next_index]) continue;
        dfs(next_index);
        dp[index][1] += min(dp[next_index][0], dp[next_index][1]);
        dp[index][0] += dp[next_index][1];
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    for(int i = 0; i < lighthouse.size(); i++){
        int start = lighthouse[i][0]; int end = lighthouse[i][1];
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    dfs(1);
    cout << dp[1][0] << ' ' << dp[1][1];
    answer = min(dp[1][0], dp[1][1]);
    return answer;
}