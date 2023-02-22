#include <iostream>

#define N 1000000
using namespace std;
bool pm[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, Q;

    for(i=2; i<=N; i++)
        pm[i] = true;

    for(i=2; i*i<=N; i++){
        if(pm[i]){
            for(j=i*i; j<=N; j+=i){
                pm[j] = false;
            }
        }
    }

    while(1){
        cin >> Q;
		if(Q == 0)
			break;

		for(i=3; i<=N; i++){
			if(pm[i] && pm[Q-i]){
				cout << Q << " = " << i << " + " << Q-i << '\n';
				break;
			}
		}
    }
}