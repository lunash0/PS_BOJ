#include <stdio.h>
#define cmp(n, m) (n >= m) ? n : m

int main(){
    int N;
    int sequence[1001] = {0};
    int dp[1001] = {0};

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &sequence[i]);
    
    int max = 0, rst = 0;
    for(int i = 1; i <= N; i++){
        max = 0;
        for (int j = 0; j < i; j++){
            if(sequence[i] > sequence[j])
                max = dp[j] >= max ? dp[j] : max;
        }
        dp[i] = max + 1;
        rst = cmp(rst, dp[i]);
    }
    printf("%d", rst);

    return 0;
}

/* q. 처음 코드 짤 때, cmp함수 정의에서 (n > m)으로 조건을 달아줬는데,
그러면 n == m 인 경우는 어떻게 처리해주는 것인가? 왜 통과를 받았는가? 18번 줄도! */
