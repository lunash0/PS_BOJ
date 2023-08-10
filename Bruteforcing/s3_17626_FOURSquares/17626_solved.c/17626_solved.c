#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ftDP(int n){
    int *dp = (int *)calloc((n + 1), sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++){
        dp[i] = i; 
            // �����غ��� min�̷��� �� �ʿ� ���� dp[i]�� ������Ʈ ���ָ� ��
            // dp[i]�� ���� ū ���� ������ i (i���� 1�� ��)
        for (int j = 2; j <= i / 2; j++){
            int tmp = j * j;
            if (tmp > i)
                break;
            dp[i] = dp[i] > dp[i - tmp] + 1 ? dp[i - tmp] + 1 : dp[i];
        }
    }
    int rst = dp[n];
    free(dp);

    return rst;
}

int main(){
    int n;
    scanf("%d", &n);

    if (n == 1 || n == 2 || n == 3)
        printf("%d", n);
    else
        printf("%d", ftDP(n));

    return 0;
}