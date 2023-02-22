#include <iostream>
using namespace std;

int i, a, b, n;

int gcd(int max, int min)
{   
    return min ? gcd(min, max % min) : max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while(n--){
        cin >> a >> b;
        if(a < b) swap(a, b);
        
        cout << a * b / gcd(a,b) << '\n';
    }
}