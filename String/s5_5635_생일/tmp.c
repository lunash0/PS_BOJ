#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char ***people, int j) {
    char **tmp = people[j];
    people[j] = people[j + 1];
    people[j + 1] = tmp;
}

int main() {
    int n;
    scanf("%d", &n);
    char ***people = (char ***)calloc(n, sizeof(char **));

    // 이름 : people[i][0], 년도: people[i][3], 월: people[i][2], 일: people[i][1]

    for (int i = 0; i < n; i++) {
        people[i] = (char **)calloc(4, sizeof(char *));
        for (int j = 0; j < 4; j++) {
            people[i][j] = (char *)calloc(16, sizeof(char));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            scanf("%s", people[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            char *year1 = people[j][3], *year2 = people[j + 1][3];
            char *month1 = people[j][2], *month2 = people[j + 1][2];
            char *day1 = people[j][1], *day2 = people[j + 1][1];

            // 수정: 년도, 월, 일 순서로 비교하여 정렬합니다.
            if (strcmp(year1, year2) < 0)
                swap(people, j);
            else if (strcmp(year1, year2) == 0) {
                if (strcmp(month1, month2) < 0)
                    swap(people, j);
                else if (strcmp(month1, month2) == 0) {
                    if (strcmp(day1, day2) < 0)
                        swap(people, j);
                }
            }
        }
    }

    // 수정: 가장 나이가 적은 사람과 가장 많은 사람을 출력합니다.
    printf("%s\n%s\n", people[0][0], people[n - 1][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            free(people[i][j]);
        free(people[i]);
    }
    free(people);

    return 0;
}
