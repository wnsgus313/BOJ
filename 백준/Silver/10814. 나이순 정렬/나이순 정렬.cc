#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n;
typedef pair <int, string> p;
p a[100001];

bool comp (p a, p b)
{
  return a.first < b.first;
}

int main(){
  cin >> n;

  for(int i=0; i<n; i++)
    cin >> a[i].first >> a[i].second;

    stable_sort(a, a+n, comp);

  for(int i=0; i<n; i++)
    cout << a[i].first << ' ' << a[i].second << "\n";

  return 0;
}
