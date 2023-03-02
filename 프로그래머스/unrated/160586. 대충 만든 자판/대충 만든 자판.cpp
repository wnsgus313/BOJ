#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int res, up;
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    
    for(int i=0; i<targets.size(); i++){
        for(int j=0; j<targets[i].length(); j++){
            res = 20000000;
            for(int k=0; k<keymap.size(); k++){
                for(int l=0; l<keymap[k].length(); l++){
                    if(keymap[k][l] == targets[i][j]){
                        res = min(res, l+1);
                        break;
                    };
                }
            }

            if(res == 20000000) {
                answer[i] = -1;
                break;
            }
            answer[i] += res;
        }
    }
    
    return answer;
}