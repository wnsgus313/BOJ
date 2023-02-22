//
//  main.cpp
//  13567
//
//  Created by 배준현 on 2018. 12. 27..
//  Copyright © 2018년 배준현. All rights reserved.
//

#include <iostream>
#include <string>
    
using namespace std;

int main(int argc, const char * argv[]) {
    int M, n;
    cin >> M >> n;
    
    string TM[1001];
    int dir[1001];
    
    int dx[4] = {1, 0, -1, 0}; // 동, 북, 서, 남
    int dy[4] = {0, 1, 0, -1}; // 동, 북, 서, 남
    int flag = 0; // 0 = 동, 1 = 북, 2 = 서, 3 = 남
    
    int col = 0, row = 0;
    bool success = 1;
    
    for(int i=0; i<n; i++)
        cin >> TM[i] >> dir[i];
    
    for(int i=0; i<n; i++){
        if(TM[i] == "TURN"){
            if(dir[i] == 0)
                flag = (flag+1) % 4;
            if(dir[i] == 1){
                if(flag == 0)
                    flag = 3;
                else
                    flag = (flag-1) % 4;
            }
        }
        else if(TM[i] == "MOVE"){
            row += dir[i]*dx[flag]; col += dir[i]*dy[flag];
        }
        
        if(col > M || row > M || col < 0 || row < 0){
            success = 0;
            break;
        }
    }
    if(success == 1)
        cout << row << ' ' << col << endl;
    else
        cout << "-1" << endl;
    
    return 0;
}