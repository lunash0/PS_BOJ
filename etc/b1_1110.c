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

/* 1. 변수 개수 제한에 대하여 :  변수 4-5개정도까지만 레지스터에 저장되고 변수 수가 더늘어나면 시피유에 저장되어서 속도가 매우 느려진다고해
    좀 더 자세히 알아보자. 
    또한, 변수개수는 5개이내로쓸것, 쓸데없는거 최대한 줄일것 
    참고링크 : https://www.memoengine.com/blog/c-%EC%96%B8%EC%96%B4-%EB%A0%88%EC%A7%80%EC%8A%A4%ED%84%B0register-%EB%B3%80%EC%88%98/*/
