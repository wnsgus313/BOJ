#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int start, finish;
vector<pair<int, int> > t;
vector<int> rooms(1);

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    for(int i=0; i<book_time.size(); i++){
        start = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
        finish = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2)) + 10;
        t.push_back(make_pair(start, finish));
    }
    
    sort(t.begin(), t.end());
    for(auto i:t){
        cout << i.first << ' ' << i.second << endl;
    }
    for(int i=0; i<book_time.size(); i++){
        int flag = 0;
        int s = t[i].first;
        int l = t[i].second;
        
        for(int j=0; j<answer; j++){
            if(rooms[j] <= s){
                rooms[j] = l;
                cout << j << endl;
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        
        ++answer;
        rooms.push_back(l);
    }
        
    return answer;
}