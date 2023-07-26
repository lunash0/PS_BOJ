#include <stdio.h>

int graph[1001][1001] = {0};
int dfsVisited[1001] = {0};
int bfsVisited[1001] = {0};
int q[1001];

void dfs(int cur, int num){
    dfsVisited[cur] = 1;
    printf("%d", cur);

    for (int i = 1; i <= num; i++){
        if (graph[cur][i] == 1 && dfsVisited[i] == 0){
            printf(" ");
            dfs(i, num);
        }
    }
}

void bfs(int cur, int num){
    int front = 0, rear = 0, popVal;
    bfsVisited[cur] = 1;
    printf("%d ", cur);
    q[0] = cur;
    rear++;

    while (front <= rear){
        popVal = q[front++];
        for (int i = 1; i <= num; i++){
            if (graph[popVal][i] == 1 && bfsVisited[i] == 0){
                printf("%d ", i);
                q[rear++] = i;
                bfsVisited[i] = 1;
            }
        }
    }
}

int main(){
    int N, M, V, x,  y;
    scanf("%d %d %d", &N, &M,&V);

    for (int i = 1; i <= M; i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    dfs(V, N);
    printf("\n");
    bfs(V, N);

    return 0;
}