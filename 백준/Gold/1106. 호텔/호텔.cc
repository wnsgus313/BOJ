#include <iostream>
#include <algorithm>
using namespace std;

int memo[1200];

int C, N, cost, costomer;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> C >> N;
  for(int i=1; i<C+100; i++){
    memo[i] = 1e9;
  }

  for(int i=0; i<N; i++){
    cin >> cost >> costomer;
    for(int j=costomer; j<C+100; j++){
      memo[j] = min(memo[j-costomer] + cost, memo[j]);
    }
  }

  cout << *min_element(memo+C, memo+C+100) << '\n';
}