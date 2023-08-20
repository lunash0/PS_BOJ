#include <stdio.h>

int N, min = 1000000000, max = -1000000000;
int nums[101], op[100];
int idx = 1;

void createOpArr(int val, int cnt) {
	for (int i=0; i<cnt; i++)
		op[idx++] = val;
}

void swap(int a, int b) {
	int tmp = op[a];
	op[a] = op[b];
	op[b] = tmp;
}

// 주어진 식 연산
void cal() {
	int sum = nums[1];
	for (int i = 1; i < N; i++) {
		switch (op[i]) {
			case 1:
				sum += nums[i + 1];
				break;
			case 2:
				sum -= nums[i + 1];
				break;
			case 3:
				sum *= nums[i + 1];
				break;
			case 4:
				sum /= nums[i + 1];
				break;
		}
	}
	if (sum > max)
		max = sum;
	if (sum < min)
		min = sum;
}

// 같은 것이 있는 순열 구하기
void permutation(int start) {
	if (start == N - 1)
		cal();
	for (int i = start; i < N; i++) {
		if (i != start && op[i] == op[start])
			continue;
		swap(i, start);
		permutation(start + 1);
		swap(i, start);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &nums[i]);
	
	int nowOpNum;
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &nowOpNum);
		if (nowOpNum != 0)
			createOpArr(i, nowOpNum);
	}
	permutation(1);
	printf("%d\n%d\n", max, min);

	return 0;
}