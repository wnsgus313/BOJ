#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i = 0;
    int n = 0;
    int fib[46] = {0};
    
    fib[0] = 0;
    fib[1] = 1;
    
    scanf("%d", &n);
    
    for(i=2; i<=n; i++){
        fib[i] = fib[i-2] + fib[i-1];
    }
    
    printf("%d\n", fib[n]);
    return 0;
}
