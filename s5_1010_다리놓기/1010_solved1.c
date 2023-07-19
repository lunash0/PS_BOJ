// 팩토리얼을 이용한 조합 구현

#include <stdio.h>

double ftFacto(int n) {
	if (n == 0)
		return 1;
	return n * ftFacto(n - 1);
}

double ftCombi(int n, int m) {
	return ftFacto(n) / (ftFacto(n - m) * ftFacto(m));
}

int main()
{
	int tc, N, M;

	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d%d", &N, &M);
		printf("%.lf\n",ftCombi(M, N));
	}

	return 0;
}
