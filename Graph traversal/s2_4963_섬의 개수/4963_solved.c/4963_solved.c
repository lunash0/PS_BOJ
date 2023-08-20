#include <stdio.h>

int map[50][50] = {0};
int visited[50][50] = {0};
// dx, dy : ╩С аб го ©Л аб╩С абго ©Лго ©Л╩С
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, 1, -1};
int w, h;

typedef struct {
    int x;
    int y;
} Point;

Point q[50 * 50];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    q[rear].x = x;
    q[rear].y = y;
    rear = (rear + 1) % (50 * 50);
}

Point dequeue() {
    Point point = q[front];
    front = (front + 1) % (50 * 50);
    return point;
}

void bfs(int x, int y) {
    enqueue(x, y);
    visited[x][y] = 1;

    while (front != rear) {
        Point current = dequeue();
        x = current.x;
        y = current.y;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < h  && ny < w) {
                if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
                    enqueue(nx, ny);
                    visited[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}