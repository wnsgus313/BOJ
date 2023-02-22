#include <iostream>
using namespace std;
int dice[3][3];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int res = 0;
int N, M, x, y, K, i, j, dir, temp;
int map[20][20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> y >> x >> K;
    for(j=0; j<N; j++){
        for(i=0; i<M; i++){
            cin >> map[j][i];
        }
    }
    while(K--){
        cin >> dir;
        if(x + dx[dir] >= M || x + dx[dir] < 0 || y + dy[dir] >= N || y + dy[dir] < 0) continue;

        x += dx[dir]; y += dy[dir];   
        if(dir == 1){
            temp = res;
            res = dice[1][0];
            for(i=0; i<2; i++)
                dice[1][i] = dice[1][i+1];
            dice[1][i] = temp;
        }
        else if(dir == 2){
            temp = res;
            res = dice[1][2];
            for(i=2; i>0; i--)
                dice[1][i] = dice[1][i-1];
            dice[1][i] = temp;
        }
        else if(dir == 3){
            temp = res;
            res = dice[0][1];
            for(i=0; i<2; i++)
                dice[i][1] = dice[i+1][1];
            dice[i][1] = temp;
        }
        else if(dir == 4){
            temp = res;
            res = dice[2][1];
            for(i=2; i>0; i--)
                dice[i][1] = dice[i-1][1];
            dice[i][1] = temp;
        }
        if(map[y][x] == 0)
            map[y][x] = dice[1][1]; 
        else{
            dice[1][1] = map[y][x];
            map[y][x] = 0;
        }
        cout << res << '\n';
    }
}