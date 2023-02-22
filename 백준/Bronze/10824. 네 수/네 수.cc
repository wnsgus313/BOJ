#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int exB=1, exD=1, B, D, temp;
    long long res = 0L, A, C;

    cin >> A >> B >> C >> D;

    temp = B;
    while(temp>=10){
        exB++;
        temp /= 10;
    }
    temp = D;
    while(temp>=10){
        exD++;
        temp /= 10;
    }
    res = A * pow(10, exB) + C * pow(10, exD) + B + D;

    cout << res;
}