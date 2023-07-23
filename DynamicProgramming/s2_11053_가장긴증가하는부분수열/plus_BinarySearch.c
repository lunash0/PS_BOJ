// --------------------- < Binary Search > ---------------------

    // ���� Ž�� (�̺� Ž��)�̶�?
        // - �����Ͱ� ���ĵǾ��ִ� �迭���� Ž�� ������ ���ݾ� �������� Ư���� ���� ã�Ƴ��� �˰���
        // - �迭�� �߰��� �ִ� ������ ���� �����Ͽ� ã���� �ϴ� �� x�� ��
            // : if x < �߰��� : �߰� �� ���� ���� ������ Ž��
            // : if x > �߰��� : �߰� �� ���� ���� ������ Ž��

     // ���� Ž���� �ð� ���⵵
        // - 



// ���� �ڵ� : Ž���� �����ϸ� �ش� �ε��� ��ȯ, �����ϸ� -1�� ��ȯ�ϴ� �ڵ�

#include <stdio.h>

int binSearch(int arr[], int len, int key){
    int left = 0, right = len - 1, mid;

    while (left <= right){
        mid = (left + right) / 2;
        if (key == arr[mid])
            return mid; // Ž�� ����
        else if (key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1; // Ž�� ����
}

int main(){
    int arr[10] = {2, 4, 5, 7, 19, 31, 32, 45, 46, 60};
    int key;

    scanf("%d", &key);
    printf("%d", binSearch(arr, 10, key));

    return 0;
}