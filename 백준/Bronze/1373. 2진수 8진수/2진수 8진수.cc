#include <iostream>
using namespace std;

string c;
int a, i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c;

    if(c.size() % 3 == 1) {cout << c[0]-'0'; a=1;}
    else if(c.size() % 3 == 2) {cout << (c[0]-'0')*2 + (c[1]-'0'); a=2;}
    else {cout << (c[0]-'0')*4 + (c[1]-'0')*2 + (c[2]-'0'); a=3;}
    for(i=0; i<(c.size()-1)/3; i++, a+=3){
        cout << (c[a]-'0')*4 + (c[a+1]-'0')*2 + (c[a+2]-'0');
    }
}