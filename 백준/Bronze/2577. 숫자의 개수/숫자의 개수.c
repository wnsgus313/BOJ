#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c;
    int result = 0;
    int i = 0;
    int arr[10] = {0};
    
    scanf("%d %d %d", &a, &b, &c);
    result = a * b * c;
    
    while(1){
        if(result <= 99 && result >= 10){
            arr[result % 10]++;
            arr[result / 10]++;
            break;
        }
        
        arr[result % 10]++;
        
        result /= 10;
    }
    
    for(i=0; i<10; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}