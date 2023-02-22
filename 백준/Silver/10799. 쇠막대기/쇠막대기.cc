#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, cnt=0, part=0;
    string str;

    cin >> str;

    for(i=0; i<str.length(); i++){

        if(str[i]=='(')
            cnt++;
        else{
            cnt--;
            if(str[i-1] == '(')
                part += cnt;
            else
                part += 1;
        }
    }

    cout << part;
}