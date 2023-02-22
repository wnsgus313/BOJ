#include <iostream>
using namespace std;

int memo[41];
int n, f1, f2;

int fib(int n){
  if(n == 1 || n == 2){
    f1++;
    return 1;
  }
  else return (fib(n-1) + fib(n - 2));
} 

void fibonacci(int n){
  memo[1] = memo[2] = 1;
  for(int i=3; i<=n; i++){
    f2++;
    memo[i] = memo[i-1] + memo[i-2];
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  fib(n);
  fibonacci(n);
  cout << f1 << ' ' << f2;
}