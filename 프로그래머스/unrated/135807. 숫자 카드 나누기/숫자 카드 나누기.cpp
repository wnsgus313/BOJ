// 1시간 15분
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

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

unordered_set<int> GetDivider(int n)
{
    unordered_set<int> s;
    
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    
    return s;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int n = arrayA.size();
    unordered_set<int> s;
    
    // 길이가 1인걸 대비해서
    arrayA.push_back(arrayA[0]);
    arrayB.push_back(arrayB[0]);

    // 초기 최대공약수
    int aGCD = GetGCD(arrayA[1], arrayA[0]);
    int bGCD = GetGCD(arrayB[1], arrayB[0]);
    
    // 최대공약수 구하기
    for(int i=2; i<n; i++){
        aGCD = GetGCD(aGCD, arrayA[i]);
    }
    for(int i=2; i<n; i++){
        bGCD = GetGCD(bGCD, arrayB[i]);
    }
    
    // 중복되지 않는 약수 구하기
    s = GetDivider(aGCD);
    unordered_set<int> t = GetDivider(bGCD);
    for(auto i=t.begin(); i!=t.end(); i++){
        // 없으면 넣기
        if(s.find(*i) == s.end()){
            s.insert(*i);
        }
        // 있으면 삭제
        else s.erase(*i);
    }
    
    // 최대값 찾기
    for(auto i=s.begin(); i!=s.end(); i++){
        answer = max(answer, *i);
    }
    
    // A,B 둘다 나눠지면 0
    if(answer == 0) return 0; // 0이면 floating point때문에 바로 return
    
    int flag = 0;
    
    for(int i=0; i<n; i++){
        if(arrayA[i] % answer == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        flag = 0;
        for(int i=0; i<n; i++){
            if(arrayB[i] % answer == 0){
                flag = 1;
                break;
            }
        }
    }
    
    if(flag) return 0;
    
    return answer;
}