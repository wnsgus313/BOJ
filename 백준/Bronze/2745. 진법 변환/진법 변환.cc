#include <iostream>
#include <cmath>
using namespace std;

char c[36];
int main()
{
    int base, i, f, res=0, ex = 0;
    string n;

    cin >> n >> base;

    for(i=0; i<10; i++) c[i] = '0' + i;
    for(i=10; i<36; i++) c[i] = 'A' + i - 10;

    for(i=n.size()-1; i>=0; i--){
        f = 0;
        while(n.at(i) != c[f]){
            f++;
        }
        res += f * pow(base, ex);
        ex++;
    }
    cout << res;
}