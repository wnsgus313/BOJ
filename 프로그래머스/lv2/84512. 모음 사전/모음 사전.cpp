#include <string>
#include <vector>

using namespace std;

string vo[5] = {"A", "E", "I", "O", "U"};
string dict;
int answer, cnt;
int visited[5];

void dfs(string s){
    // 문자가 사전과 같으면 순서 저장 후 종료
    if(s == dict){
        answer = cnt;
        return;
    }
    
    // 검색 길이가 사전 최대 길이면 종료
    if(s.length() >= 5){
        return;
    }

    for(int i=0; i<5; i++){
        cnt++;
        dfs(s + vo[i]);
    }
}

int solution(string word) {
    dict = word;
    
    dfs("");
    
    return answer;
}