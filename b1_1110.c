// < 더하기 사이클 >
#include <stdio.h> 

int main(void) {
    
    int a = 0, b = 0, c = 0, d = 0;
    int input = 0, cnt = 0;
    
    scanf("%d", &input);
    int rst = input;
    
    while(d != rst) {
        a = input / 10;
        b = input % 10;
        c = (a+b) % 10;
        d = (b*10) + c;
        input = d;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
