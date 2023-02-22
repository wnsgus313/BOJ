#include <iostream>
#include <cmath>
using namespace std;

int cols[16];
int N, res;

bool check(int row){
  for(int i=0; i<row; i++){
    if(cols[row] == cols[i] || row-i == abs(cols[row] - cols[i])){
      return false;
    }
  }

  return true;
}

void nqueen(int row){
  if(row == N){
    res++;
    return;
  }

  for(int i=0; i<N; i++){
    cols[row] = i; 
    if(check(row)){
      nqueen(row+1);
      cols[row] = 0;
    }
  }
}

int main()
{
  cin >> N;
  nqueen(0);
  cout << res;
}