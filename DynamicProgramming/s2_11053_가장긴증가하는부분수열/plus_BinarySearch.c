// --------------------- < Binary Search > ---------------------

    // 이진 탐색 (이분 탐색)이란?
        // - 데이터가 정렬되어있는 배열에서 탐색 범위를 절반씩 좁혀가며 특정한 값을 찾아내는 알고리즘
        // - 배열의 중간에 있는 임의의 값을 선택하여 찾고자 하는 값 x와 비교
            // : if x < 중간값 : 중간 값 기준 좌측 데이터 탐색
            // : if x > 중간값 : 중간 값 기준 우측 데이터 탐색

     // 이진 탐색의 시간 복잡도
        // - 



// 예시 코드 : 탐색에 성공하면 해당 인덱스 반환, 실패하면 -1을 반환하는 코드

#include <stdio.h>

int binSearch(int arr[], int len, int key){
    int left = 0, right = len - 1, mid;

    while (left <= right){
        mid = (left + right) / 2;
        if (key == arr[mid])
            return mid; // 탐색 성공
        else if (key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1; // 탐색 실패
}

int main(){
    int arr[10] = {2, 4, 5, 7, 19, 31, 32, 45, 46, 60};
    int key;

    scanf("%d", &key);
    printf("%d", binSearch(arr, 10, key));

    return 0;
}