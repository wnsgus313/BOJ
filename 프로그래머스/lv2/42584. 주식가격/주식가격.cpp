#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
stack<pair<int, int> > s;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    s.push({prices[0], 0});
    
    for(int i=1; i<prices.size(); i++){
        int price = s.top().first;
        int idx = s.top().second;
        
        if(price <= prices[i]){
            s.push({prices[i], i});
        }
        else if(price > prices[i]){            
            while(!s.empty() && s.top().first > prices[i]){
                idx = s.top().second;
                answer[idx] = i - idx;
                s.pop();
            }
            s.push({prices[i], i});
        }
    }
    
    while(!s.empty()){
        int idx = s.top().second;
        answer[idx] = prices.size() - idx - 1;
        s.pop();
    }
    
    return answer;
}