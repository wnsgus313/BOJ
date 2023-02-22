#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int i;
	string str, str2;
	
    getline(cin, str);
	
    for(i=0; i<str.length(); i++){
        if(islower(str[i])){
            str[i] = 'a' + ((str[i] % 'a') + 13) % 26;
        }
        else if(isupper(str[i])){
            str[i] = 'A' + ((str[i] % 'A') + 13) % 26;
        }
        
    }
    cout << str;
    return 0;
}