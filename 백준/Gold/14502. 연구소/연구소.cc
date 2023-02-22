#include <iostream>
#include <vector>

using namespace std;

int map[8][8], cpmap[8][8];
bool visit[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > set0;
vector<pair<int, int> > set2;
int N, M, res, tres;

int check(int y, int x){
    if(y>=0 && x>=0 && y<N && x<M) return 1;
    else return 0;
}
void dfs(int y, int x){
    visit[y][x] = true;
    cpmap[y][x] = 2;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(ny, nx)){
            if(cpmap[ny][nx] != 1 && visit[ny][nx] == false){
                dfs(ny, nx);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 0)
                set0.push_back(make_pair(i, j));
            else if(map[i][j] == 2)
                set2.push_back(make_pair(i, j));
        }
    }

    for(int k=0; k<set0.size()-2; k++){
        for(int i=k+1; i<set0.size()-1; i++){
            for(int j=i+1; j<set0.size(); j++){
                for(int y=0; y<N; y++){
                    for(int x=0; x<M; x++){
                        cpmap[y][x] = map[y][x];
                        visit[y][x] = false;
                    }
                }
                cpmap[set0[k].first][set0[k].second] = 1;
                cpmap[set0[i].first][set0[i].second] = 1;
                cpmap[set0[j].first][set0[j].second] = 1;

                for(int t=0; t<set2.size(); t++){
                    dfs(set2[t].first, set2[t].second);
                }
                for(int y=0; y<N; y++){
                    for(int x=0; x<M; x++){
                        if(cpmap[y][x] == 0)
                            tres++;
                    }
                }
                if(tres > res) res = tres;
                tres = 0;
            }
        }
    }
    cout << res;
}