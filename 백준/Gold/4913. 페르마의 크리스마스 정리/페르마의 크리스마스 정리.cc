//
//  main.cpp
//  4913
//
//  Created by 배준현 on 2018. 12. 31..
//  Copyright © 2018년 배준현. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1000001
#define DIMAX 1001

int a=0, b=0;
int a1=0, b1=0;
int diff = 0;
int modN = 0;
int prime[MAX] = {0};
bool PrimeArray[MAX];
int c = 0;

void Eratos(int n)
{
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }
    
    for(int i=2; i<=n; i++){
        if(PrimeArray[i] == true){
            prime[c] = i;
            c++;
        }
    }
}

void boundN(void)
{
    for(int i=a1; i<=b1; i++){
        if(i == 0)
            modN++;
        if(prime[i] % 4 == 1)
            modN++;
    }
}

int main(int argc, const char * argv[]) {
    Eratos(MAX-1);
 
    while(1){
        cin >> a >> b;
        
        if(a == -1 && b == -1)
            return 0;
        
        if(a > b){
            int temp = b;
            b = a;
            a = temp;
        }

        a1 = lower_bound(prime, prime+c, a) - prime;
        b1 = upper_bound(prime, prime+c, b) - prime - 1;
        diff = b1 - a1 + 1;
        
        boundN();
        
        cout << a << ' ' << b << ' ' << diff << ' ' << modN << endl;
        
        modN = 0;
    }
    
    
    return 0;
}
