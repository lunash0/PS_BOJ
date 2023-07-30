#include <stdio.h>

int adj[101][101] = {0};
int visited[101] = {0};
int n;

int degreeOfKinship(int start, int end){
    int queue[101];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    int level = 0;
    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int current = queue[front++];
            if (current == end)
                return level;
            for (int j = 1; j <= n; j++) {
                if (adj[current][j] == 1 && !visited[j]) {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }
        }
        level++;
    }

    return -1;
}

int main() {
    int m, x, y;

    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }

    int result = degreeOfKinship(x, y);
    printf("%d\n", result);

    return 0;
}