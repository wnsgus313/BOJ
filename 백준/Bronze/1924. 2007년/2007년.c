#include <stdio.h>

int main(int argc, const char * argv[]) {
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month = 0;
    int day = 0;
    int i = 0;
    int count = 0;
    char str[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    scanf("%d %d", &month, &day);
    
    for(i=0; i<month-1; i++){
        count += arr[i];
    }
    count += day;
    
    count %= 7 ;
    printf("%s\n", str[count]);
    
    return 0;
}
