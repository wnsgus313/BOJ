#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Student
{
    string name;
    int kor;
    int eng;
    int mat;
};

bool cmp(const Student& a, const Student& b)
{
    return make_tuple(-a.kor, a.eng, -a.mat, a.name) < make_tuple(-b.kor, b.eng, -b.mat, b.name);
}

int main()
{
    int n, i;
    scanf("%d", &n);

    vector<Student> s(n);

    for(i=0; i<n; i++){
        cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].mat;
    }

    sort(s.begin(), s.end(), cmp);

    for(i=0; i<n; i++)
        cout << s[i].name << "\n";
    return 0;
}