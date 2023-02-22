#include <iostream>
#include <cstring>
using namespace std;

int t, n, c[101], i , j;
long long s;

int gcd(int max, int min)
{   
    while(min > 0){
        int temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        memset(c, 0, sizeof(c));
        s = 0L;
        cin >> n;
        for(i=0; i<n; i++){
            cin >> c[i];
        }

        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                s += gcd(max(c[i], c[j]), min(c[i], c[j]));
            }
        }
        cout << s << '\n';
    }
}