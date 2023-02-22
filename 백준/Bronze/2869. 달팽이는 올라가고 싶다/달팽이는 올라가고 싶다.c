#include <stdio.h>

int main(int argc, const char * argv[]) {
    int A, B, V;
    int dis = 0;
    int day = 0;

    scanf("%d %d %d", &A, &B, &V);

    dis = A - B;

    day = (V-B-1) / dis;

    printf("%d\n", day+1);
    
    return 0;
}
