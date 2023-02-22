#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, i, j, c[10001]={0,};

    cin >> n;
    for(i=1; i<=n; i++){
        cin >> t;
        c[t]++; 
    }

    for(i=1; i<=10000; i++)
        for(j=0; j<c[i]; j++)
            cout << i << '\n';
}