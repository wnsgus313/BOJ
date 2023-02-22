#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string cmd;
    int i, cnt, val;
    queue<int> q;

    cin >> cnt;
    while(cnt--){
        cin >> cmd;

        if(cmd == "push"){
            cin >> val;
            q.push(val);
        }
        else if(cmd == "front"){
            if(!q.empty())
                cout << q.front() << '\n';
            else
                cout << "-1\n";
        }
        else if(cmd == "back"){
            if(!q.empty())
                cout << q.back() << '\n';
            else
                cout << "-1\n";
        }
        else if(cmd == "size")
            cout << q.size() << '\n';
        else if(cmd == "empty"){
            (!q.empty()) ? cout << "0\n" : cout << "1\n";
        }
        else if(cmd == "pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << "-1\n";
            }
            
        }
    }
}