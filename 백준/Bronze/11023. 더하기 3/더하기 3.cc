#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string str="asvx xvasd", temp;
    vector<string> s;
    int res=0;

    s.clear();

    getline(cin, str);
    istringstream ss(str);
    
    while(getline(ss, temp, ' ')){
        s.push_back(temp);
    }

    for(auto& v:s){
        res += stoi(v);
    }

    cout << res;
}

    