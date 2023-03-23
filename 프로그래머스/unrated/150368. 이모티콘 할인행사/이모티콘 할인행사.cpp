#include <vector>

using namespace std;

int plusUser, cost, length;
vector<int> discount = {10, 20, 30, 40};
vector<vector<int> > combination;

void makeCombination(int s, vector<int> percent){
    if(length == s){
        combination.push_back(percent);
        return;
    }
    
    for(int j=0; j<discount.size(); j++){
        percent.push_back(discount[j]);
        makeCombination(s+1, percent);
        percent.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    length = emoticons.size();
    vector<int> percent;
    makeCombination(0, percent);
    
    for(int i=0; i<combination.size(); i++){
        int tCost = 0;
        int tPlusUser = 0;
        
        for(int j=0; j<users.size(); j++){
            int purchaseDiscount = users[j][0];
            int budget = users[j][1];
            int c = 0;

            for(int k=0; k<emoticons.size(); k++){
                if(purchaseDiscount > combination[i][k]){
                    continue;
                }
                c += emoticons[k] * (100-combination[i][k]) / 100;
            }
            if(c >= budget){
                tPlusUser++;
            }
            else{
                tCost += c;
            }
        }
        
        if(tPlusUser > plusUser){
            plusUser = tPlusUser;
            cost = tCost;
        }
        else if(tPlusUser == plusUser && tCost > cost){
            cost = tCost;
        }
    }
    
    answer.push_back(plusUser);
    answer.push_back(cost);
    return answer;
}