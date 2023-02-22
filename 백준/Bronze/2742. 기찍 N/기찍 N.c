#include <stdio.h>

int main()
{
    int i = 0;
    int n = 0;
    
    scanf("%d", &n);
    
    for(i=n; i>=1; i--){
        printf("%d\n", i);
    }
    
    return 0;
}