// 파스칼의 삼각형을 활용한 조합 구현
// pos를 입력받는 방식 대신 좌표를 입력받아 값을 반환하는 방식으로 바꿈
// 여러 개의 tc를 반복할 수 있도록 바꿈

#include <stdio.h>
#include <stdlib.h>

int ftPascalTriangle(int** triangle, int M, int N){	
	for(int i = 0; i <= M; i++)
		triangle[i] = (int *)malloc(sizeof(int) * (i + 1));
	triangle[0][0] = triangle[1][0] = triangle[1][1] = 1;

	if (M == 0 || M == 1)
		return 1;	
	for (int x = 2; x <= M; x++){
		for (int y = 0; y <= x; y++){
			if (y == 0 || x == y)
				triangle[x][y] = 1;
			else
				triangle[x][y] = triangle[x - 1][y - 1] + triangle[x - 1][y];
			if (x == M && y == N)
				return (triangle[x][y]);
		}
	}
	return 0;
}

int main(){
	int tc, N, M;
	scanf("%d", &tc);
	for (int cases = 0; cases < tc; cases++){
		scanf("%d %d", &N, &M);

		// 파스칼의 삼각형 틀 만들기
		int **triangle = (int **)malloc(sizeof(int *) * (M + 1));
		// 결과 출력
		printf("%d\n", ftPascalTriangle(triangle, M, N));
		for (int i = 0; i <= M; i++) // 각행에 대한 메모리 해제 깜빡했었음
			free(triangle[i]);
		free(triangle);
	}

	return 0;
}
