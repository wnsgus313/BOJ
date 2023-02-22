#include <iostream>
#include <utility>
#include <deque>

#define MAX 102
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[MAX][MAX];
int Ls[MAX];
char Ld[MAX];

int N, K, i, j, L, Lsidx, t1, t2, d, time;
bool flag = false;
deque<pair<int, int>> snake;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> K;
    for(i=0; i<K; i++){
        cin >> t1 >> t2;
        board[t1][t2] = 1;
    }
    cin >> L;
    for(i=0; i<L; i++){
        cin >> Ls[i] >> Ld[i];
    }

    snake.push_back(make_pair(1, 1));

    while(!flag && snake.back().first<=N && snake.back().second<=N && snake.back().first>=1 && snake.back().second>=1){

        t1 = snake.back().first + dy[d];
        t2 = snake.back().second + dx[d];
        
        for(i=0; i<snake.size(); i++){
            if(snake[i].first == t1 && snake[i].second == t2)
                flag = 1;
        }

        time++;
        snake.push_back(make_pair(t1, t2));

        if(!board[t1][t2]){
            snake.pop_front();
        }
        else
            board[t1][t2] = 0;
        
        if(time == Ls[Lsidx]){
            if(Ld[Lsidx] == 'D'){
                d = (d+1) % 4;
            }
            else{
                d = (d+3) % 4;
            }
            Lsidx++;
        }
    }
    cout << time;
}