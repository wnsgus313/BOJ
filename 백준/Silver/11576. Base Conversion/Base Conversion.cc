#include <iostream>
#include <cmath>
using namespace std;

void conV(int n, int b)
{
    if(n < b)
        cout << n << " ";
    else{
        conV(n/b, b);
        cout << n % b << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, m, i, j, t=0;
    int n[26];

    cin >> A >> B >> m;
    for(i=0; i<m; i++)
        cin >> n[i];

    for(i=0, j=m-1; i<m; i++, j--){
        t += n[i] * pow(A, j);
    }
    conV(t, B);
}