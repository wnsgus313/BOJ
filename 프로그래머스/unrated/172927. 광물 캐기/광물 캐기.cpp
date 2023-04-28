// 1시간
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] > b[2];
        }
        
        return a[1] > b[1];
    }
    return a[0] > b[0];
}

int cost[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}}; // 비용
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int n = minerals.size(); // 광물 개수
    vector<vector<int> > cnt; // 광물 5개씩 묶음으로 광물 개수 저장 {dia, iron, stone}
    int type; // 광물 종류
    
    int c = 0;
    for(int i=0; i<3; i++){
        c += picks[i];
    }
    
    // 5개씩 읽어서 각 광물 개수 파악하기
    for(int i=0; i<c*5 && i<n; i++){
        int idx = i / 5; // 5개씩 묶기
        
        if(minerals[i] == "diamond") type = 0;
        else if(minerals[i] == "iron") type = 1;
        else if(minerals[i] == "stone") type = 2;
        
        if(i % 5 == 0){
            vector<int> v(3);
            cnt.push_back(v); // 새로운 백터 공간 만들어주기
        }
        cnt[idx][type]++; // 광물 개수 추가
    }
    
    // 곡갱이를 사용할 수 있을만큼만 정렬
    sort(cnt.begin(), cnt.end(), comp); // 가장 높은 광물이 많은 순으로 내림차순 정렬
    
    for(int i=0; i<cnt.size(); i++){
        int pick = -1 ;
        
        for(int j=0; j<3; j++){
            // 곡갱이가 남아있으면 선택 후 개수를 줄인 후 종료
            if(picks[j] != 0){
                pick = j;
                picks[j]--;
                break;
            }
        }
        
        if(pick == -1) break; // 곡갱이가 안남아있으면 종료
        
        for(int j=0; j<3; j++){
            answer += cost[pick][j] * cnt[i][j]; // 비용 * 개수
        }
    }
    
    return answer;
}