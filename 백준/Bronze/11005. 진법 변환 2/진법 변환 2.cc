#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, base, i;
    vector<int> v;

    cin >> n >> base;

    while(n > 0){
        v.push_back(n % base);
        n /= base;
    }
    
    vector<int>::reverse_iterator iter;
    for(iter=v.rbegin(); iter != v.rend(); iter++){
        if(*iter >= 10){
            char c = *iter - 10 + 'A';
            cout << c;
        }
        else
        cout << *iter;
    }
}