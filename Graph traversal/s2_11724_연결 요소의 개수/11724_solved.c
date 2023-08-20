# include <stdio.h>

int N, M, board[1001][1001] = {0}, visited[1001] = {0};

int dfs(int cur){
    visited[cur] = 1;

    for (int i = 1; i <= N; i++){
        if (board[cur][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main(){
    scanf("%d %d", &N, &M);

    int x, y, components = 0;
    for (int i = 0; i < M; i++){
        scnaf("%d %d", &x, &y);
        board[x][y] = board[y][x] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (board[i][j] == 1 && visited[j] == 0){
                dfs(j);
                components++;
            }
        }
    }
    for (int i = 1; i <= N; i++){
        if (visited[i] == 0)
            components++;
    }
    printf("%d", components);

    return 0;
}