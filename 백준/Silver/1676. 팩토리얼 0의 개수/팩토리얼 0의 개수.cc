#include <iostream>
using namespace std;
int n, i;

int divi(int num, int d);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    cout << min(divi(n, 5), divi(n, 2));

    return 0;
}

int divi(int num, int d)
{
    int cnt = num / d;
    if(num == 0)
        return 0;
    return cnt + divi(num/d, d);
}