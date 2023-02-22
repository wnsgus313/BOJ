#include <stdio.h>
#include <algorithm>

#define MAX 1000001

int n;
int a[MAX];
int max = -1000001, min = 1000001;

int main() {
  scanf("%d", &n);

	while (n--) {
		scanf("%d", &a[n]);
    max = std::max(a[n], max); min = std::min(a[n], min);
	}
  
  printf("%d %d\n", min, max);
}