#include <iostream>
#include <cmath>
using namespace std;

int x_1, y_1, x_2, y_2, cx[50], cy[50], r[50];
int n, test_case, res;

bool In_Planet(int x, int y, int idx){
  if(pow(x-cx[idx], 2) + pow(y-cy[idx], 2) < pow(r[idx], 2)){
    return 1;
  }

  return 0;
}
bool Out_Planet(int x, int y, int idx){
  if(pow(x-cx[idx], 2) + pow(y-cy[idx], 2) > pow(r[idx], 2)){
    return 1;
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> test_case;

  for(int i=0; i<test_case; i++){
    res = 0;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    cin >> n;
    for(int j=0; j<n; j++){
      cin >> cx[j] >> cy[j] >> r[j];
    }

    for(int j=0; j<n; j++){
      // 한 점이 행성 안에 있고 다른 한 점이 밖에 있을 때 행성 개수 세기
      if(In_Planet(x_1, y_1, j) && Out_Planet(x_2, y_2, j) || In_Planet(x_2, y_2, j) && Out_Planet(x_1, y_1, j)){
        res++;
      }
    }

    cout << res << '\n';
  }
}