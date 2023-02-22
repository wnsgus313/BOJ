#include <iostream>
#include <algorithm>
using namespace std;

int A[5000001];
int N, K, i, idx;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for(i=0; i<N; i++)
        cin >> A[i];
    
    nth_element(A, A + (K-1), A+N);

    cout << A[K-1];
}