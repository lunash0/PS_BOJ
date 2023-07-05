// <쉽게 푸는 문제>
#include <stdio.h>

void ftFillValue(int *arr)
{
    int cnt = 0, i, j;

    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (cnt == 1000) break;
            arr[cnt] = i;
            cnt++;
        }
    }
}

int main(){
    int A, B, sum = 0, i;
    int arr[1000] = {0};

    scanf("%d %d", &A, &B);

    ftFillValue(arr);
    for (i = A - 1; i < B; i++) // 처음에 i = A; i <= B 라고 써서 인덱스가 하나씩 더 크게 밀려남
        sum += arr[i];
    printf("%d\n", sum);

    return 0;
}

// < 스터디 후 기록 및 고찰>
// 수열의합 원리같은거 이용해서 풀어보기
// 내가 풀었던 방법 : 배열에 먼저 1000칸을 조건대로 다 채워두고 A,B를 받은 뒤 arr[A-1]부터 arr[B]까지 누적합을 구함
/* 새로 풀어볼 방법 : 배열에 1 2 2 3 3 3 4 4 4 4 ... 이런 식을 저장 말고 1 3 5 8 11 ... 이런식으로 각 칸에 1부터 현재까지의 누적합을 저장
    그 후, A와 B를 입력 받으면 2 4  arr[B] - arr[A-1]을 바로 해줘버리는거임
    그러면 실행시간이 훨씬 줄어들겠지?
    근데 의문 : 그럼 어짜피 누적합 저장할 때 시간은 어떻게되지?? */
