#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num = 0;
    int count[10001] = {0};
    int outPut = 0;
    int i = 0;
    int k = 1;
    
    scanf("%d %d", &num, &outPut);
    
    for(i=1; i<=num/2; i++){
        if(num % i == 0){
            count[k] = i;
            k++;
        }
    }
    
    count[k] = num;
    
    if (count[outPut] == 0) {
        printf("0\n");
    }
    else
        printf("%d\n", count[outPut]);
    
    return 0;
}