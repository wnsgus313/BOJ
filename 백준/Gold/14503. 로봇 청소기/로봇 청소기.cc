#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int map[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int nx, ny;
int N, M, r, c, d, flag=1, res;

int check(int y, int x){
    if(y>=0 && x>=0 && y<N && x<M) return 1;
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    while(flag){
        if(flag == 1){
            res++;
            map[r][c] = 2;
            flag = 2;
        }
        else if(flag == 2){
            for(int i=0; i<4; i++){
                ny = dy[(d+3)%4];
                nx = dx[(d+3)%4];
                if(map[r+ny][c+nx]==0 && check(r+ny, c+nx)){
                    r += ny;
                    c += nx;
                    d = (d+3)%4;
                    flag = 1;
                    break;
                }
                else if(map[r+ny][c+nx]!=0 && check(r+ny, c+nx)){
                    d = (d+3)%4;  
                }
                if(i==3){
                    ny = dy[(d+2)%4];
                    nx = dx[(d+2)%4];
                    if(map[r+ny][c+nx] == 1 || !check(r+ny, c+nx)){
                        flag = 0;
                    }
                    r += ny;
                    c += nx;
                }

            }
        }
    }
    printf("%d", res);
}