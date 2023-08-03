#include <stdio.h>
#include <string.h>

int main() {
    char name[51];
    int cnt[26] = {0};
    int oddCnt = 0;
    char oddChar = 0;

    scanf("%s", name);

    for (int i = 0; name[i] != '\0'; i++)
        cnt[name[i] - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            oddCnt++;
            oddChar = i + 'A';
        }
    }

    if (oddCnt > 1)
        printf("I'm Sorry Hansoo\n");
    else {
        char result[51];
        int idx = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++)
                result[idx++] = i + 'A';
        }
        if (oddCnt == 1)
            result[idx++] = oddChar;
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++)
                result[idx++] = i + 'A';
        }
        result[idx] = '\0';
        printf("%s\n", result);
    }

    return 0;
}