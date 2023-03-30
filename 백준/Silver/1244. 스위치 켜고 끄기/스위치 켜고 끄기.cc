#include <iostream>
#include <vector>

using namespace std;

int N, c, s, num;
vector<int> swi;

int main()
{
  cin >> N;
  swi.resize(N);

  for(int i=0; i<N; i++){
    cin >> swi[i];
  }

  cin >> c;
  while(c--){
    cin >> s >> num;

    if(s == 1){
      for(int i=0; i<N; i++){
        if((i+1) % num != 0) continue;
        swi[i] = !swi[i];
      }
    }
    else if(s == 2){
      for(int i=0; i<N; i++){
        int left = num - i - 1;
        int right = num + i - 1;

        if(left < 0 || right >= N || swi[left] != swi[right]) break;
        swi[left] = !swi[left];
        if(i == 0) continue;
        swi[right] = !swi[right];
      }
    }
  }

  for(int i=0; i<swi.size(); i++){
    if(i != 0 && i % 20 == 0) cout << '\n';
    cout << swi[i] << ' ';
  }
  return 0;
}