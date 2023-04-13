#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// 시간 순으로 오름차순 정렬
bool comp(vector<string>& a, vector<string>& b){
    int minuteA = stoi(a[1].substr(0, 2));
    int secondA = stoi(a[1].substr(3, 2));
    int timeA = 60 * minuteA + secondA;
    int minuteB = stoi(b[1].substr(0, 2));
    int secondB = stoi(b[1].substr(3, 2));
    int timeB = 60 * minuteB + secondB;
    
    return timeA < timeB;
}

// 시간 문자열을 초로 변환
int StringToSecond(string t)
{
    int minute = stoi(t.substr(0, 2));
    int second = stoi(t.substr(3, 2));
    int time = 60 * minute + second;
    
    return time;
}

int n;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    n = plans.size();
    
    // 시간 오름차순 정렬
    sort(plans.begin(), plans.end(), comp);
    
    vector<pair<string, pair<int, int> > > times; // 과제, 시작 시간, 걸리는 시간을 담은 vector
    stack<pair<string, int> > remains; //과제, 남은 시간을 담은 queue
    
    for(int i=0; i<n; i++){
        times.push_back({plans[i][0], {StringToSecond(plans[i][1]), stoi(plans[i][2].substr(0, plans[i][2].length()))}});
    }

    for(int i=0; i<n-1; i++){
        string subject = times[i].first;
        int currentT = times[i].second.first;
        int remainT = times[i].second.second;
        int nextStartT = times[i+1].second.first; // 다음 시작시간
        
        // 시간 + 남은 시간이 다음 시작시간보다 크면
        // 남은 시간 - (다음 시작시간 - 시간)를 해주고 스택에 넣기
        if(currentT + remainT > nextStartT){
            remainT = remainT - (nextStartT - currentT);
            remains.push({subject, remainT}); 
        }
        
        // 시간 + 남은 시간이 작거나 같으면 answer에 넣고 현재 시간을 걸린 시간 더해주기
        else {
            answer.push_back(subject);
            currentT += remainT;
            
            // 반복문으로 스택 맨 위에 있는 시간을 다음 시작시간까지 빼서 집어넣기
            while(!remains.empty()){
                string remainSubject = remains.top().first;
                int remainTime = remains.top().second;
                remains.pop();
                
                if(currentT + remainTime > nextStartT){
                    remainTime = remainTime - (nextStartT - currentT);
                    remains.push({remainSubject, remainTime}); 
                    break;
                }
                else{
                    answer.push_back(remainSubject);
                    currentT += remainTime;
                }
            }
        }
    }
    
    answer.push_back(times[n-1].first);
    while(!remains.empty()){
        answer.push_back(remains.top().first);
        remains.pop();
    }

    return answer;
}