#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, n, s, score;
int like[5] = {0, 1, 10, 100, 1000};
int likes[401][4];
int arr[21][21];
int blank[21][21];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<int> order;

bool check(int r, int c){
  if(r < 1 || c < 1 || r > N || c > N) return false;
  return true;
}

void fillBlank(){
  for(int r=1; r<=N; r++){
    for(int c=1; c<=N; c++){
      int cnt = 0;
      for(int i=0; i<4; i++){
        if(check(r+dy[i], c+dx[i])){
          cnt++;
        }
      }
      blank[r][c] = cnt;
    }
  }
}

vector<pair<int, int> > findLike(int student){
  int cnt = 0;
  vector<pair<int, int> > ret;

  for(int r=1; r<=N; r++){
    for(int c=1; c<=N; c++){
      int count = 0;
      if(arr[r][c] != 0) continue;
      for(int i=0; i<4; i++){
        int ny = r + dy[i], nx = c + dx[i];
        if(check(ny, nx)){
          for(int j=0; j<4; j++){
            if(likes[student][j] == arr[ny][nx]) count++;
          }
        }
      }

      if(cnt < count){
        cnt = count;
        ret.clear();
      }
      if(cnt == count){
        ret.push_back(make_pair(r, c));
      }
    }
  }

  return ret;
}

vector<pair<int, int> > findBlank(vector<pair<int, int> > lst){
  int cnt = 0, r, c;
  vector<pair<int, int> > ret;
  for(int i=0; i<lst.size(); i++){
    r = lst[i].first;
    c = lst[i].second;

    if(blank[r][c] > cnt){
      ret.clear();
      cnt = blank[r][c];
    }
    if(blank[r][c] == cnt){
      ret.push_back(make_pair(r, c));
    }
  }

  return ret;
}

void getScore(){
  for(int r=1; r<=N; r++){
    for(int c=1; c<=N; c++){
      int student = arr[r][c];
      int cnt = 0;
      for(int i=0; i<4; i++){
        int ny = r + dy[i];
        int nx = c + dx[i];
        for(int j=0; j<4; j++){
          if(check(ny, nx) && likes[student][j] == arr[ny][nx]){
            cnt++;
          }
        }
      }
      score += like[cnt];
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  n = N*N;
  fillBlank();

  for(int i=0; i<n; i++){
    cin >> s;
    order.push_back(s);
    for(int j=0; j<4; j++){
      cin >> likes[s][j];
    }
  }

  for(int i=0; i<n; i++){
    auto lst = findLike(order[i]);

    if(lst.size() > 1){
      lst = findBlank(lst);
    }
    
    int r = lst[0].first;
    int c = lst[0].second;

    for(int i=0; i<4; i++){
      int ny = r + dy[i];
      int nx = c + dx[i];
      if(check(ny, nx)){
        blank[ny][nx]--;
      }
    }

    arr[r][c] = order[i];
  }

  getScore();
  cout << score;
}