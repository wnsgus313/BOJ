// #include <iostream>

// using namespace std;

// int arr[100][100];
// int A, B, N, M, i, j;
// int x, y, robotNo, rept, flag;
// char d, operation;
// int robo[100][2];
// int robot[100];
// int dx[4] = {-1, 0, 1, 0}; // N, E, S, W
// int dy[4] = {0, 1, 0, -1};

// int check(int robotNo, int x, int y) {
//   if(x>=0 && x<A && y>=0 && y<B){
//     if(arr[x][y] == 0 && arr[x][y] == 0){
//       arr[x][y] = robotNo;
  
//       return -1;
//     }
//     return arr[x][y];
//   }
//   return -2;
// }

// int main()
// {
//   scanf("%d %d %d %d", &A, &B, &N, &M);
//   for(i=0; i<N; i++) {
//     scanf("%d %d %c", &x, &y, &d);

//     arr[x-1][y-1] = i+1;
//     robo[i][0] = x-1;
//     robo[i][1] = y-1;
//     switch (d) {
//       case 'N':
//         robot[i] = 1;
//         break;
//       case 'E':
//         robot[i] = 2;
//         break;
//       case 'S':
//         robot[i] = 3;
//         break;
//       case 'W':
//         robot[i] = 0;
//         break;
//     }
//   }

//   for(i=0; i<M; i++){
//     int exit = 0;
//     if(exit) break;
    
//     scanf("%d %c %d", &robotNo, &operation, &rept);
    
//     for(j=0; j<rept; j++){
//       switch (operation)
//       {
//         case 'L':
//           robot[robotNo-1] = (robot[robotNo-1] + 3) % 4; 
//           break;
//         case 'R':
//           robot[robotNo-1] = (robot[robotNo-1] + 1) % 4;
//           break;
//         case 'F':
//           int tx = robo[robotNo-1][0], ty = robo[robotNo-1][1];
//           robo[robotNo-1][0] += dx[robot[robotNo-1]]; 
//           robo[robotNo-1][1] += dy[robot[robotNo-1]];
          
//           flag = check(robotNo, robo[robotNo-1][0], robo[robotNo-1][1]);

//           if(flag == -1) {
//             arr[tx][ty] = 0;
//             exit = 1;
//           }
//           else if(flag == -2) {
//             cout << "Robot " << robotNo << " crashes into the wall";
//             return 0;
//           } else {
//             cout << "Robot " << robotNo << " crashes into robot " << flag;
//             return 0;
//           }
//           break;
//       }
//     }
//   }
//   cout << "OK";
// }
#include <iostream>

using namespace std;

int posX[101];
int posY[101];
char dir[101];

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    int N, M;
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        cin >> posX[r] >> posY[r] >> dir[r];
    }
    for (int m = 0; m < M; m++) {
        int robot;
        char action;
        int repeat;
        cin >> robot >> action >> repeat;
        if (action == 'L' || action == 'R') {
            repeat %= 4;
        }
        for (int rep = 0; rep < repeat; rep++) {
            if (action == 'F') {
                int xd = 0;
                int yd = 0;
                switch (dir[robot]) { 
                    case 'N':
                        yd = 1; break;
                    case 'E':
                        xd = 1; break;
                    case 'S':
                        yd = -1; break;
                    case 'W':
                        xd = -1; break;
                }
                posX[robot] += xd;
                posY[robot] += yd;
                if (    posX[robot] <= 0 ||
                        posX[robot] > A ||
                        posY[robot] <= 0 ||
                        posY[robot] > B) {
                    cout << "Robot " << robot << " crashes into the wall\n";
                    for (m++; m < M; m++) {
                        cin >> robot >> action >> repeat;
                    }
                    return;
                }
                for (int r = 1; r <= N; r++) {
                    if (r != robot && posX[r] == posX[robot] &&
                                      posY[r] == posY[robot]) {
                        cout << "Robot " << robot << " crashes into robot "
                             << r << "\n";
                        for (m++; m < M; m++) {
                            cin >> robot >> action >> repeat;
                        }
                        return;
                    }
                }
            }
            else if (action == 'R') {
                switch (dir[robot]) {
                    case 'N':
                        dir[robot] = 'E'; break;
                    case 'E':
                        dir[robot] = 'S'; break;
                    case 'S':
                        dir[robot] = 'W'; break;
                    case 'W':
                        dir[robot] = 'N'; break;
                }
            }
            else if (action == 'L') {
                switch (dir[robot]) {
                    case 'N':
                        dir[robot] = 'W'; break;
                    case 'W':
                        dir[robot] = 'S'; break;
                    case 'S':
                        dir[robot] = 'E'; break;
                    case 'E':
                        dir[robot] = 'N'; break;
                }
            }
        }
    }
    cout << "OK\n";
}

int main()
{
  run();
}