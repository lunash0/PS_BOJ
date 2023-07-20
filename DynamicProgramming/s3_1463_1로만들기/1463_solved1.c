// define MIN 사용

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int *dpTab = (int *)malloc(sizeof(int) * (N + 1));
    dpTab[0] = dpTab[1] = 0;

    for (int i = 2; i <= N; i++) {
        dpTab[i] = dpTab[i - 1] + 1;
        if (i % 2 == 0)
            dpTab[i] = min(dpTab[i], dpTab[i / 2] + 1);
        if (i % 3 == 0)
            dpTab[i] = min(dpTab[i], dpTab[i / 3] + 1);
    }

    printf("%d", dpTab[N]);
    free(dpTab);

    return 0;
}
