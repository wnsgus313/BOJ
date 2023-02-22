#include <cstdio>

int arr[9][9], N;

int go(int y, int x) {
    if (x >= 9) return go(y + 1, 0);
    if (y >= 9) return 1;
    if (arr[y][x]) return go(y, x + 1);

    //빈칸이 아니었을 때
    int chk[10] = { 0, };
    
    // check 배
    for (int i = 0; i < 9; ++i) chk[arr[y][i]] = chk[arr[i][x]] = 1;
    int yy = y / 3 * 3, xx = x / 3 * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            chk[arr[yy + i][xx + j]] = 1;

    // 가능한 숫자들에 대해서 backtracking
    for (int i = 1; i <= 9; ++i) {
        if (!chk[i]) {
            arr[y][x] = i;
            if (go(y, x + 1)) return 1;
            arr[y][x] = 0;
        }
    }
    return 0;
}

void print() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            printf("%d", arr[i][j]);
        puts("");
    }
}

int main() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            scanf("%1d", &arr[i][j]);

    go(0, 0);
    print();
}