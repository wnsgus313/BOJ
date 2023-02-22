//
//  main.cpp
//  2606
//
//  Created by 배준현 on 2018. 12. 29..
//  Copyright © 2018년 배준현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10000

int visit[MAX];
vector<int> g[MAX];

int num = 0;
int pn = 0;
int a, b;

static int ct = 0;

void dfs(int start){
    if(visit[start]){
        // 방문한경우 리턴
        return;
    }
    visit[start] = true; // 체크
    
    ct++;
    
    for(int i=0; i< g[start].size(); i++){
        // 인접한 노드 방문
        int x = g[start][i];
        dfs(x);
    }
}

int main(int argc, const char * argv[]) {
    cin >> num >> pn;
    
    for(int i=0; i<pn; i++){
        cin >> a >> b;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout << ct-1 << endl;

    return 0;
}
