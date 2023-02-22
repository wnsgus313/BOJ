#include <iostream>
using namespace std;
int n, r;
long long A, B, i;

long long divi(int num, int d);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> r;

    A = divi(n, 5) - divi(n-r, 5) - divi(r, 5);
    B = divi(n, 2) - divi(n-r, 2) - divi(r, 2);
    cout << min(A, B);

    return 0;
}

long long divi(int num, int d)
{
    long long cnt = 0;
    for(i=d; i<=num; i*=d){
        cnt += num / i;
    }
    return cnt;
}