#include <stdio.h>

int main(int argc, const char * argv[]) {
    int arr[5][4] = {0};
    int total[5] = {0};
    int i = 0;
    int j = 0;
    int flag = -1;
    int check = 0;
    
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            scanf("%d", &arr[i][j]);
            total[i] += arr[i][j];
        }
    }
    
    for(i=0; i<5; i++){
        if(flag < total[i]){
            flag = total[i];
            check = i;
        }
    }
    
    printf("%d %d\n", check+1, flag);
    
    return 0;
}
