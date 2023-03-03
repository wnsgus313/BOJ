#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int c1, c2;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    vector<int> check(goal.size());
    for(int i=0; i<goal.size(); i++){
        if(cards1[c1] == goal[i]){
            c1++;
        }    
        else if(cards2[c2] == goal[i]){
            c2++;
        }
        else{
            answer = "No";
        }
    }
    return answer;
}