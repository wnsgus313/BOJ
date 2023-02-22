#include <stdio.h>

int main()
{
    int fac = 0;
    int i = 0;
    int result = 1;
    
    scanf("%d", &fac);
    
    for(i=1; i<=fac; i++){
        result *= i;
    }
    if(fac == 0)
        result = 1;
    
    printf("%d\n", result);
    
    return 0;
}