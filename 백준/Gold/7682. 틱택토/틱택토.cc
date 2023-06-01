// 1시간 2분
#include <iostream>
#include <string>
using namespace std;

string tic, res;
char turns[2] = {'X', 'O'};

void Valid(string cur, int turn, int idx){
  // 승패 결정났거나 꽉차면 종료 => 승패 결정 났을 때 같으면 valid
  int flag = 1; // 승패 결정났거나 꽉차면 1

  // 꽉 안찼으면 0
  for(int i=0; i<9; i++){
    if(cur[i] == '.'){
      flag = 0;
      break;
    }
  }

  for(int i=0; i<3; i++){
    string s1 = "", s2 = ""; // 가로, 세로 확인
    for(int j=i*3; j<i*3+3; j++){
      s1 += cur[j];
    }
    for(int j=i; j<9; j+=3){
      s2 += cur[j];
    }
    if(s1 == "OOO" || s1 == "XXX" || s2 == "OOO" || s2 == "XXX"){
      flag = 1;
      break;
    }
  }

  // 대각선
  string s1 = cur.substr(0, 1) + cur.substr(4, 1) + cur.substr(8, 1);
  string s2 = cur.substr(2, 1) + cur.substr(4, 1) + cur.substr(6, 1);

  if(s1 == "OOO" || s1 == "XXX" || s2 == "OOO" || s2 == "XXX"){
    flag = 1;
  }

  // 같으면 valid
  if(cur == tic && flag){
    res = "valid";
    return;
  }
  if(flag){
    return;
  }


  // X부터 두고, 번갈아 가면서 둔다
  for(int i=0; i<9; i++){
    // 자리 비었으면 넘기기 || 현재 turn과 다르면 넘기기 || 자리가 이미 차지됐으면 넘기기
    if(tic[i] == '.' || tic[i] != turns[turn] || cur[i] != '.') continue;
    
    cur[i] = turns[turn];
    
    Valid(cur, !turn, idx+1);
    
    if(res == "valid") return;
    cur[i] = '.';
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  while(1){
    cin >> tic;
    if(tic == "end") break;

    res = "invalid";
    Valid(".........", 0, 0);
    cout << res << "\n";
  }
}