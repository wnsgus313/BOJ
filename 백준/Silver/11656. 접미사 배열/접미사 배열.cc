#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    vector<string> str;
    string s;
    int i;

    cin >> s;

    for(i=0; i<s.length(); i++){
        str.push_back(s.substr(i));
    }
    sort(str.begin(), str.end());
    for(auto v : str){
        cout << v << '\n';
    }
}