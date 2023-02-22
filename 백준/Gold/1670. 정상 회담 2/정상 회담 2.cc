#include <iostream>

#define MAX 10001

using namespace std;
long long memo[MAX];
int N, i, j;

int main(int argc, const char * argv[]) {
    cin >> N;
    
    memo[0] = 1;
    memo[2] = 1;
    memo[4] = 2;
    for(i=6; i<=N; i+=2){
        for(j=0; j<i; j+=2){
            memo[i] += memo[j] * memo[i-(j+2)];
            memo[i] %= 987654321;
        }
    }
    cout << memo[N] << endl;
    
    return 0;
}