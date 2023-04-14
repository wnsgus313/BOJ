#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long l = 1;
    long long r = 2e18;
    
    sort(times.begin(), times.end());
    
    // 종료 조건: l > r
    while(l <= r){
        long long mid = (l + r) / 2;
        long long tn = n;
        
        // 현재 시간 안에 n명을 커버하는지 확인
        for(int i=0; i<times.size(); i++){
            if(tn <= 0) break;
            tn -= mid / times[i];
        }
        
        // 커버 못함 -> 시간을 늘린다.
        if(tn > 0){
            l = mid + 1;
        }
        // 커버함 -> 시간을 줄여본다.
        else{
            r = mid - 1;
        }
    }
    
    answer = l;
    
    return answer;
}