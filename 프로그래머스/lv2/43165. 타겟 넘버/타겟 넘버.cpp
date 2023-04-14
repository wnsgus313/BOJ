#include <string>
#include <vector>

using namespace std;

int goal, n;
int answer;

// sum = 지금까지 합, cnt = 몇개 선택했는지
void dfs(vector<int> numbers, int sum, int cnt){

    // cnt를 n개 선택하고 합이 target이랑 맞으면 더하기
    if(cnt >= n){
        if(sum == goal) answer++; 
        return;
    }
    
    dfs(numbers, sum + numbers[cnt], cnt+1);
    dfs(numbers, sum - numbers[cnt], cnt+1);
    
    return;
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    goal = target;
    
    dfs(numbers, 0, 0);
    
    return answer;
}