#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char arr[101];
    int i = 0;
    int outPut[27] = {0};
    
    scanf("%s", arr);
    
    for(i=0; i<strlen(arr); i++){
        if(arr[i] >= 97 && arr[i] <= 122){
            outPut[arr[i]-97]++;
        }
    }
    
    for(i=0; i<26; i++){
        printf("%d ", outPut[i]);
    }
    
    
    return 0;
}