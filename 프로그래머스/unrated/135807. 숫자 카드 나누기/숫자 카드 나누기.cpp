// 1시간 15분
#include <algorithm>
#include <vector>

using namespace std;
int n;

int GetGCD(int l, int r)
{
    // 항상 l >= r
    if(l < r) swap(l, r);

    while(1){
        int t = l % r;
        if(t == 0) return r;

        l = r;
        r = t;
    }
}

int f(vector<int>& arrayA, vector<int>& arrayB){    
    int gcd = arrayA[0]; // 초기 gcd
    
    for(int i : arrayA){
        gcd = GetGCD(gcd, i);
    }
    
    for(int i : arrayB){
        // gcd로 나누어지면 0 리턴
        if(i % gcd == 0){
            return 0;
        }
    }
    
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    n = arrayA.size();
    
    answer = max(f(arrayA, arrayB), f(arrayB, arrayA));

    return answer;
}
