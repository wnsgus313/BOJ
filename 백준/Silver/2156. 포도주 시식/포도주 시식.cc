//
//  main.cpp
//  2156
//
//  Created by 배준현 on 2018. 12. 28..
//  Copyright © 2018년 배준현. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int Dp[10001] = {0};
int cap[10001];

int main(int argc, const char * argv[]) {
    cin >> n;
    
    cap[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> cap[i];
    }
    
    Dp[0] = 0;
    Dp[1] = cap[1];
    Dp[2] = cap[1] + cap[2];
    
    for(int i=3; i<=n; i++){
        Dp[i] = max(Dp[i-3]+cap[i-1]+cap[i], max(Dp[i-2]+cap[i], Dp[i-1]+Dp[0])); // 0+2, 1+1, 2+0
    }
    cout << Dp[n] << endl;
    
    return 0;
}
