// ���� ��忡�� ���� ��尡 �̾��� ���� ��� ���� ���� �̵� �� �湮�� ��� �� ��ŭ ����ϴ� �⺻ DFS ����
#include <stdio.h>

int computer[101][101] = {0};
int visited[101] = {0};
int infected = -1;  // 1�� ��ǻ�ʹ� �����ϰ� ����� �ϹǷ� -1

void dfs(int start, int num){

    visited[start] = 1;
    infected++;

    for (int i = 1; i <= num; i++){
        if (computer[start][i] == 1 && visited[i] == 0)
            dfs(i, num);
    }
}

int main(){
    int num, net, x, y; // ������� ��ǻ���� ��, ������� ��, �Է¹��� ��(x, y�� ����Ǿ��ִٴ� ��)
    scanf("%d", &num);
    scanf("%d", &net);

    // ��Ʈ��ũ ���� ���� �Է¹ޱ�
    for (int i = 0; i < net; i++){
        scanf("%d %d", &x, &y);
        computer[x][y] = computer[y][x] = 1;
    }
    dfs(1, num); // 1�� ��ǻ�ͺ��� ���̷��� �۶߸��� ����
    printf("%d", infected);

    return 0;
}