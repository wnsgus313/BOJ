#include <iostream>
#define N 1000000

using namespace std;
bool pm[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, p1, p2;

    for(i=2; i<=N; i++)
        pm[i] = true;

    for(i=2; i*i<=N; i++){
        if(pm[i]){
            for(j=i*i; j<=N; j+=i){
                pm[j] = false;
            }
        }
    }

    cin >> p1 >> p2;
    for(i=p1; i<=p2; i++)
        if(pm[i]) cout << i << '\n';
}