#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair <int, int>> v;
int l, r;
int n;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d %d", &l, &r);
    v.push_back(pair<int, int> (l, r));
  }

  sort(v.begin(), v.end());

  for(int i=0; i<n; i++)
    printf("%d %d\n", v[i].first, v[i].second);

  return 0;
}
