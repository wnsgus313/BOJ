#include <iostream>
#include <queue>
using namespace std;

int i, j, N, K;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    
    for(i=1; i<=N; i++){
        q.push(i);
    }
    cout << "<";
    for(i=0; i<N; i++){
        for(j=0; j<K-1; j++){
            q.push(q.front());
            q.pop();
        }
        if(i == N-1)
            cout << q.front() << ">";
        else
            cout << q.front() << ", ";
        q.pop();
    }
}