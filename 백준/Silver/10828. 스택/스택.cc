#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> s;
    int cnt, i, val, res;
    string cmd;

    cin >> cnt;

    while(cnt--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> val;
            s.push(val);
        }
        else if(cmd == "pop"){
            if(!s.empty()){
                cout << s.top() << '\n';
                s.pop();
            }
            else
                cout << "-1\n";
        }
        else if(cmd == "size")
            cout << s.size() << '\n';
        else if(cmd == "top"){
            if(!s.empty()){
                cout << s.top() << '\n';
            }
            else
                cout << "-1\n";
        }
        else if(cmd == "empty"){
            if(!s.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
    }
}