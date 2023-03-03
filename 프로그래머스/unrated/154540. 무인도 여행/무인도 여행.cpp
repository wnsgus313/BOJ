#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int w, h;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int dfs(int y, int x, vector<string>& maps){
    int ret = maps[y][x] - '0';
    maps[y][x] = 'X';

    for(int i=0; i<4; i++){
        int ny = y+dy[i], nx = x+dx[i];
        if(0 <= ny && ny < h && 0 <= nx && nx < w && maps[ny][nx] != 'X')
            ret += dfs(ny, nx, maps);
    }
    
    return ret;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    w = maps[0].length();
    h = maps.size();
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(maps[i][j] != 'X'){
                answer.push_back(dfs(i, j, maps));
            }
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}