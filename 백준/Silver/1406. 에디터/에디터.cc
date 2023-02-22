#include <iostream>
#include <list>

using namespace std;

int n;
string s;
char com, P;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    
    list<char> c(s.begin(), s.end());
    auto p = c.end();
    cin >> n;
  
    while(n--){
        cin >> com;
        if(com == 'L'){
            if(p != c.begin()) p--;
        }
        else if(com == 'D'){
            if(p != c.end()){
                p++;
            }
        }
        else if(com == 'B'){
            if(p != c.begin()){
                p = c.erase(--p);
            }
        }
        else if(com == 'P'){
            cin >> P;
            c.insert(p, P);
        }
    }
    for(auto& iter : c)
        cout << iter;
}