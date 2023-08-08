#include <stdio.h>

int isHansu(int n){
    int tmpN = n, len = 0, i = 0;
    int nArr[4] = {0};

    while (tmpN > 0){
        nArr[i++] = tmpN % 10;
        tmpN /= 10;
        len++;
    }
    if (len == 1 || len == 2)
        return 1;
    int diff = nArr[1] - nArr[0];
    if (len == 3){
        if (nArr[2] - nArr[1] == diff)
            return 1;
    }
    else{
        if (nArr[2] - nArr[1] == diff && nArr[3] - nArr[2] == diff)
            return 1;
    }

    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    int cnt = 0;

    for (int i = 1; i <= N; i++){
        if (isHansu(i) == 1)
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
