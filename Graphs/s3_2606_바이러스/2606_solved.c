// 현재 노드에서 다음 노드가 이어져 있을 경우 다음 노드로 이동 후 방문한 노드 수 만큼 출력하는 기본 DFS 문제
#include <stdio.h>

int computer[101][101] = {0};
int visited[101] = {0};
int infected = -1;  // 1번 컴퓨터는 제외하고 세어야 하므로 -1

void dfs(int start, int num){

    visited[start] = 1;
    infected++;

    for (int i = 1; i <= num; i++){
        if (computer[start][i] == 1 && visited[i] == 0)
            dfs(i, num);
    }
}

int main(){
    int num, net, x, y; // 순서대로 컴퓨터의 수, 연결망의 수, 입력받을 쌍(x, y가 연결되어있다는 뜻)
    scanf("%d", &num);
    scanf("%d", &net);

    // 네트워크 연결 정보 입력받기
    for (int i = 0; i < net; i++){
        scanf("%d %d", &x, &y);
        computer[x][y] = computer[y][x] = 1;
    }
    dfs(1, num); // 1번 컴퓨터부터 바이러스 퍼뜨리기 시작
    printf("%d", infected);

    return 0;
}