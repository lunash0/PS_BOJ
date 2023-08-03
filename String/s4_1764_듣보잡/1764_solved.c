#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpStr(char* a, char* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char** unheard = (char**)malloc(n * sizeof(char*));
    char** unseen = (char**)malloc(m * sizeof(char*));

    for (int i = 0; i < n; i++) {
        unheard[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", unheard[i]);
    }
    for (int i = 0; i < m; i++) {
        unseen[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", unseen[i]);
    }

    qsort(unheard, n, sizeof(char*), cmpStr); // 배열, 요소 개수, 요소 하나 크기, 비교 함수 포인터
    qsort(unseen, m, sizeof(char*), cmpStr);

    int cnt = 0, size = n > m ? n : m;
    char **result = (char**)malloc(sizeof(char *) * size);
    for (int i = 0, j = 0; i < n && j < m;) {
        int cmp = strcmp(unheard[i], unseen[j]);
        if (cmp == 0) {
            result[cnt] = (char*)malloc(21 * sizeof(char));
            strcpy(result[cnt], unheard[i]);
            cnt++; i++; j++;
        }
        else if (cmp < 0)
            i++;
        else
            j++;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%s\n", result[i]);

    for (int i = 0; i < n; i++)
        free(unheard[i]);
    for (int i = 0; i < m; i++)
        free(unseen[i]);
    for (int i = 0; i < cnt; i++)
        free(result[i]);
    free(unheard);
    free(unseen);
    free(result);

    return 0;
}
