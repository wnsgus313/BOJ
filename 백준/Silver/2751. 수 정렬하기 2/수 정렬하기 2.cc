#include <cstdio>
#include <algorithm>

int n, i;
int arr[1000001];

int main() {
  scanf("%d", &n);
  
  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);
  std::sort(arr, arr+n);

  for(i=0; i<n; i++)
    printf("%d\n", arr[i]);

  return 0;
}