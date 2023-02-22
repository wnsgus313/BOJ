#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num = 0;
    int primeN[1000] = {0};
    int count = 0;
    int flag = 0;
    
    scanf("%d", &num);
    
    for(int i=0; i<num; i++)
        scanf("%d", &primeN[i]);

    for(int i=0; i<num; i++){
        flag = 0;
        for(int j=2; j<=primeN[i]/2+1; j++){
            if(primeN[i] % j == 0){
                flag = 0;
                break;
            }
            else
                flag = 1;
        }
        if(flag == 1)
            count++;
        else if(primeN[i] == 2)
          count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}