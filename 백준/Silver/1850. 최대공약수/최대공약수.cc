#include <iostream>
using namespace std;

long long i, a, b, n;

long long gcd(long long max, long long min)
{   
    return min==0 ? max : gcd(min, max % min);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    if(a < b) swap(a, b);
    
    n = gcd(a,b);
    for(i=0; i<n; i++)
        cout << "1";
}