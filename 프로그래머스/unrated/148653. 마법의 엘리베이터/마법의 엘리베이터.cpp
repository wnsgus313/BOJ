// 1시간 30분
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int n = to_string(storey).size();
    
    for(int i=0; i<n; i++){
        string t = to_string(storey); // 잘라서 쓸 임시 변수
        int num = t[t.length()-i-1] - '0'; // 마지막 부터 자리 숫자
        int fNum = -1; // 앞자리 숫자, 앞자리가 없으면 -1
        
        if(i != n-1){
            fNum = t[t.length()-i-2] - '0';
        }
        
        // 5 미만이면 층 빼기
        if(num < 5) {
            answer += num;
            storey -= num * pow(10, i);
        }
        // 5 초과면 층 더하기
        else if(num > 5){
            answer += 10 - num;
            storey += (10 - num) * pow(10, i);
        }
        // 5면 중간을 기점으로 확인
        else if(num == 5){
            // 숫자가 5고 앞자리가 없으면 내림 
            if(fNum == -1){
                answer += num;
                storey -= num * pow(10, i);
            }
            // 숫자가 5고 앞자리가 있으면
            else{
                // 앞자리가 5 이상이면 더하기
                if(fNum >= 5){
                    answer += 10 - num;
                    storey += (10 - num) * pow(10, i);
                }
                // 앞자리가 5이하면 뺴기
                else{
                    answer += num;
                    storey -= num * pow(10, i);
                }
            }
        }
    }
    
    // storey의 숫자가 커지면 1번 빼주기, ex) 999 => 1000
    if(n < to_string(storey).length()) answer++;
    
    return answer;
}