#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int num = 0;
    int spend[1000] = {0};
    int result = 0;
    int fib = 0;
    
    scanf("%d", &num);
    
    for(int i=0; i<num; i++)
        scanf("%d", & spend[i]);
    
    for(int i=0; i<num; i++){
        for(int j=0; j<num-1; j++){
            if(spend[j] > spend[j+1]){
                int temp = spend[j];
                spend[j] = spend[j+1];
                spend[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<num; i++){
        fib += spend[i];
        result += fib;
    }
    
    printf("%d\n", result);
    
    return 0;
}