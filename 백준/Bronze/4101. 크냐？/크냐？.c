#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int num1 = -1;
    int num2 = -1;
    
    
    scanf("%d %d", &num1, &num2);
    while(num1!=0 && num2!=0){
        if(num1 > num2)
            printf("Yes\n");
        else
            printf("No\n");
        
        scanf("%d %d", &num1, &num2);
    }
    
    return 0;
}