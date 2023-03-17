#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[64][64];
int visited[64][64];
int temp[64][64];
vector<int> L;
int sum, res, N, Q, l, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

bool check(int y, int x) {
  if (y < 0 || y >= N || x < 0 || x >= N)
    return false;
  return true;
}
void rotate(int y, int x, int n) {
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      temp[y+i][x+j] = arr[y + n - j - 1][x+i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[y+i][x+j] = temp[y+i][x+j];
    }
  }
}
void substractIce() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (check(ny, nx) && arr[ny][nx] > 0) {
          ++cnt;
        }
      }
      if (cnt < 3) {
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    if (arr[y][x] > 0)
      --arr[y][x];
    q.pop();
  }
}
int getRes(int y, int x) {
  if (visited[y][x] || !arr[y][x]) {
    return 0;
  }

  int ret = 1;
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (check(ny, nx) && !visited[ny][nx]) {
      ret += getRes(ny, nx);
    }
  }

  return ret;
}
void getIce() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum += arr[i][j];

      if (!visited[i][j]) {
        res = max(res, getRes(i, j));
      }
    }
  }
}

int main() {
  cin >> N >> Q;
  N = pow(2, N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < Q; i++) {
    cin >> l;
    L.push_back(l);
  }

  for (int i = 0; i < L.size(); i++) {
    int n = pow(2, L[i]);
    for(int i=0; i<N; i+=n){
      for(int j=0; j<N; j+=n){
        rotate(i, j, n);;
      }
    }
    substractIce();
  }
  getIce();

  cout << sum << ' ' << res;
}