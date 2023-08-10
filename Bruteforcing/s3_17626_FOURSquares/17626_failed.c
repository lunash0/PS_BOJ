// 시간 초과
#include <stdio.h>
#include <stdlib.h>

int ftDP(int *dp, int n){
    int min = 0;

    int i = 4;
    for (i = 4; i <= n; i++){
        min = dp[1] + dp[i - 1];
        int j = 2;
        for (j = 2; j <= i / 2; j++){
            if (i / j == j && i % j == 0){
                dp[i] = 1;
                break;
            }
            else
                min = min > dp[j] + dp[i - j] ? dp[j] + dp[i - j] : min;
        }
        if (i / j == j && i % j == 0)
            continue;
        else
            dp[i] = min;
    }
    i--;

    return dp[i];
}

int main(){
    int n;

    scanf("%d", &n);
    int *dp = (int *)calloc((n + 1), sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    if (n == 1 || n == 2 || n == 3){
        printf("%d", n);
        return 0;
    }
    printf("%d", ftDP(dp, n));
    free(dp);

    return 0;
}