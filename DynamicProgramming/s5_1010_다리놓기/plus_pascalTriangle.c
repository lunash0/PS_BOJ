// pos를 입력받았을 때, 파스칼 삼각형에서 pos번째 자리의 수 출력하기 ((0,0)이 pos = 1)
#include <stdio.h>
#include <stdlib.h>

int ftPascalTriangle(int** triangle, int row, int pos){	
	for(int i = 0; i < row; i++)
		triangle[i] = (int *)malloc(sizeof(int) * (i + 1));
	
	// 기본 값 세팅 : 상위에 위치한 세 자리
	triangle[0][0] = triangle[1][0] = triangle[1][1] = 1;
	if (pos == 1 || pos == 2 || pos == 3)
		return 1;
	
	// 각 위치에 값 채우기 + 원하는 위치의 값 탐색 동시에 하기
	int tmpPos = 3;
	for (int x = 2; x <= row; x++){
		for (int y = 0; y <= x; y++){
			// 좌우로 끝 자리인 경우는 무조건 1
			if (y == 0 || x == y)
				triangle[x][y] = 1;
			// 좌우 끝 자리를 제외한 모든 자리에 대한 경우
			else
				triangle[x][y] = triangle[x - 1][y - 1] + triangle[x - 1][y];
			// 원하는 pos 위치인지 학인, pos 위치라면 tmpPos자리의 값 반환하고 끝내기
			tmpPos++;
			if (tmpPos == pos)
				return (triangle[x][y]);
		}
	}
	return 0;
}

int main(){
	int pos;
	scanf("%d", &pos);

	int sum = 0, row = 0;
	for (int i = 1; sum <= pos; i++){
		sum += i;
		row++;
	}
	if (sum < row)
		row++;
	// 파스칼의 삼각형 틀 만들기
	int **triangle = (int **)malloc(sizeof(int) * row);
	// 결과 출력
	printf("%d", ftPascalTriangle(triangle, row, pos));
	free(triangle);

	return 0;
}
