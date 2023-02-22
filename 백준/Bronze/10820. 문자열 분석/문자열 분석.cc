#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, res[4]={0,};
    string str;

    while(getline(cin, str)){
        for(i=0; i<str.length(); i++){
            if(islower(str.at(i)))
                res[0]++;
            else if(isupper(str.at(i)))
                res[1]++;
            else if(isdigit(str.at(i)))
                res[2]++;
            else if(isspace(str.at(i)))
                res[3]++;
        }
        for(i=0; i<4; i++)
            cout << res[i] << " ";
        memset(res, 0, sizeof(res));
        cout << "\n";
    }
}