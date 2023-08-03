#include <stdio.h>

int main(){
    long long S, num = 0, sum = 0;
    scanf("%d", &S);

    while(1){
        num++;
        sum += num;
        if (sum > S){
            num--;
            break;
        }
    }
    printf("%d\n", num);

    return 0;
}