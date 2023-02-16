#include <iostream>
#include <vector>
using namespace std;

int N, x, y, o;
vector<pair<int, int> > person;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> x >> y;
    person.push_back(make_pair(x, y));
  }

  for(int i=0; i<N; i++){
    o = 1;
    for(int j=0; j<N; j++){
      if(i != j && person[i].first < person[j].first && person[i].second < person[j].second){
        o++;
      }
    }
    cout << o << ' ';
  }
}