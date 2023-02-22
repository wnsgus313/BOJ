#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c, cnt, i, idx=0, max=0;
    long long n[100001]={0,};

    cin >> c;

    for(i=0; i<c; i++){
        cin >> n[i];
    }

    sort(n, n+c);
    
    cnt = 1;
    for(i=0; i<c-1; i++){
        if(n[i]==n[i+1]){
            cnt++;
            if(max < cnt){
                max = cnt;
                idx = i;
            }
        }
        else
            cnt = 1;
    }

    cout << n[idx];
}