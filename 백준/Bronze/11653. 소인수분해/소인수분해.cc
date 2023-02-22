#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n;
    cin >> n;
    
    for(i=2; i*i<=n; i++){
        while(n % i == 0){
            cout << i << '\n';
            n /= i;
        }
    }
    if(n != 1) cout << n;

    return 0;
}