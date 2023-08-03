#include <stdio.h>
#include <stdlib.h>

int cmp(int *n1, int *n2){
    if (*(int*)n1 > *(int*)n2)
        return -1;
    else if (*(int*)n1 < *(int*)n2)
        return 1;

    return 0;
}

int main(void){
    int N, i, weight = 0;
    int *rope;

    scanf("%d", &N);
    rope = (int *)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++)
        scanf("%d", &rope[i]);

    qsort(rope, N, sizeof(int), cmp);

    for(i = 0; i < N; i++)
        weight = weight > rope[i] * (i + 1) ? weight : rope[i] * (i + 1);
    printf("%d\n", weight);
    free(rope);

    return 0;
}