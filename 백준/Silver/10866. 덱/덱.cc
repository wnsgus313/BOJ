#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string cmd;
    int i, cnt, val;
    deque<int> dq;

    cin >> cnt;
    while(cnt--){
        cin >> cmd;

        if(cmd == "push_front"){
            cin >> val;
            dq.push_front(val);
        }
        else if(cmd == "push_back"){
            cin >> val;
            dq.push_back(val);
        }
        else if(cmd == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
                cout << "-1\n";
        }
        else if(cmd == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
                cout << "-1\n";
        }
        else if(cmd == "size")
            cout << dq.size() << "\n";
        else if(cmd == "empty"){
            (!dq.empty()) ? cout << "0\n" : cout << "1\n";
            
        }
        else if(cmd == "front"){
            (!dq.empty()) ? cout << dq.front() << "\n" : cout << "-1\n";
        }
        else if(cmd == "back"){
            (!dq.empty()) ? cout << dq.back() << "\n" : cout << "-1\n";
        }
    }

    return 0;
}