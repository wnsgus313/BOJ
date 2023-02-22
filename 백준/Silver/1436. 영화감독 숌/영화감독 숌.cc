#include <iostream>
using namespace std;

int N, res=1, c;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> N;
  
  while(c < N){
    int t = res;
    int n = 0;

    while(t){
      int a = t % 10;
      t /= 10;

      if(a == 6){
        n++;

        if(n == 3){
          c++;
          break;
        }
        continue;
      }
    
      n = 0;
    }

    res++;
  }

  cout << res - 1;
}