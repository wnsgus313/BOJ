#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A, P, val, sum;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> P;
    v.push_back(A);
    val = v[0];
    while(1){
        sum = 0;

        while(val != 0){
            sum += pow(val % 10, P);
            val /= 10;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] == sum){
                cout << i;
                return 0;
            }
        }
        v.push_back(sum);
        val = sum;
    }
}