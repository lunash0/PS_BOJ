#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    int *dpTab = (int *)malloc(sizeof(int) * (N + 1));
    dpTab[0] = dpTab[1] = 0;
    dpTab[2] = dpTab[3] = 1;
    for (int i = 4; i <= N; i++){
        if (i % 2 == 0)
            dpTab[i] = dpTab[i / 2] + 1 < dpTab[i - 1] + 1? dpTab[i / 2] + 1 : dpTab[i - 1] + 1;
        else if (i % 3 == 0)
            dpTab[i] = dpTab[i / 3] + 1 < dpTab[i - 1] + 1? dpTab[i / 3] + 1 : dpTab[i - 1] + 1;
        else
            dpTab[i] = dpTab[i - 1] + 1;
    }
    printf("%d", dpTab[N]);
    free(dpTab);

    return 0;
}
