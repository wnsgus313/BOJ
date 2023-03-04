#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


string res = "NO";
int N;
char arr[6][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int, int> > teacher;

bool check(int y, int x){
  if(x >= N || x < 0 || y >= N || y < 0) return false;
  return true;
}
bool discover(){
  for(int i=0; i<teacher.size(); i++){
    int y = teacher[i].first;
    int x = teacher[i].second;
    
    for(int j=0; j<4; j++){
      for(int k=1; k<N; k++){
        int ny = y + dy[j] * k;
        int nx = x + dx[j] * k;
        if(check(ny, nx)){
          if(arr[ny][nx] == 'O'){
            break;
          }
          if(arr[ny][nx] == 'S'){
            return true;
          }
        }
        else{
          break;
        }
      }
    }
  }

  return false;
}
void go(int n){
  if(n >= 4) return;
  if(res == "YES") return;
  
  if(n == 3){
    if(!discover()){
      res = "YES";
    }
    return;
  }
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(arr[i][j] == 'X'){
        arr[i][j] = 'O';
        go(n+1);
        arr[i][j] = 'X';
      }
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N;
  int startY, startX;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'T'){
        teacher.push_back(make_pair(i, j));
      }
      
    }
  }

  go(0);
  cout << res;
}