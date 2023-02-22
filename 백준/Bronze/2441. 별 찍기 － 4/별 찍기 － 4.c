#include <stdio.h>

int main()
{
    int i = 1;
    int j = 0;
    int n = 0;
    
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<i; j++)
            printf(" ");
        for(j=n; j>=i; j--)
            printf("*");
        printf("\n");
    }
}