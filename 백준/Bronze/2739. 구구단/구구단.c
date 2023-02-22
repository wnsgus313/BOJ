#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n = 0;
    int i = 0;
    
    scanf("%d", &n);
    
    for(i=1; i<=9; i++){
        printf("%d * %d = %d\n", n, i, n*i);
    }
    
    return 0;
}