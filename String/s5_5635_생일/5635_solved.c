#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void swap(char **person1, char **person2){
//     char **tmp;
//     tmp = person1;
//     person1 = person2;
//     person2 = tmp;
// }

void swap(char ***people, int j){
    char **tmp = people[j];
    people[j] = people[j + 1];
    people[j + 1] = tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    char ***people = (char ***)calloc(n, sizeof(char **));
    // 이름 : people[i][0], 년도: people[i][3], 월: people[i][2], 일: people[i][1]

    for (int i = 0; i < n; i++){
        people[i] = (char **)calloc(4, sizeof(char *));
        for (int j = 0; j < 4; j++){
            people[i][j] = (char *)calloc(16, sizeof(char)); // 왜 scanf여따넣으면 안돼..?
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 4; j++)
            scanf("%s", people[i][j]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            char *year1 = people[j][3], *year2 = people[j + 1][3];
            char *month1 = people[j][2], *month2 = people[j + 1][2];
            char *day1 = people[j][1], *day2 = people[j + 1][1];
            if (strcmp(year1, year2) > 0)
                continue;
            else if (strcmp(year1, year2) < 0)
                swap(people, j);
            else{
                if (strcmp(month1, month2) > 0)
                    continue;
                else if (strcmp(month1, month2) < 0)
                    swap(people, j);
                else{
                    if (strcmp(day1, day2) > 0)
                        continue;
                    else
                        swap(people, j);
                }
            }
        }
    }
    printf("%s\n%s\n%s\n%s\n%s", people[0][0], people[1][0], people[2]
    [0], people[3][0], people[n - 1][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) 
            free(people[i][j]);
        free(people[i]);
    }
    free(people);

    return 0;
}