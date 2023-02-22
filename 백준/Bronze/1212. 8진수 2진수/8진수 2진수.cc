#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    char c1[8][4] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    string s;
    int i;

    cin >> s;
    cout << c1[s[0]-'0'];
    for(i=1; i<s.size(); i++)
        cout << c[s[i]-'0'];
}