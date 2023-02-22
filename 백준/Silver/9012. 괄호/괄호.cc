#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, buf;
    int i, cnt=0, n;

    cin >> n;

    while(n--){
        cin >> str;
        for(i=0; i<str.length(); i++){
            if(str.at(i) == '(')
                cnt++;
            else
                cnt--;
            if(cnt < 0) break;
        }

        cnt==0 ? cout << "YES\n" : cout << "NO\n";
        
        cnt = 0;
    }
}