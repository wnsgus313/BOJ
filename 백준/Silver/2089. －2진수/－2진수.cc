#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> v;

    cin >> N;

    while(N != 1 && N != 0){
        if(N % -2 == -1) v.push_back(1);
        else v.push_back(N % -2);
        N =  ceil(N / -2.0);
    }
    if(N % -2 == -1) v.push_back(1);
    else v.push_back(N % -2);
    
    vector<int>::reverse_iterator riter;
    for(riter=v.rbegin(); riter!=v.rend(); riter++)
        cout << *riter;

    return 0;
}