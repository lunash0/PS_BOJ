#include <stdio.h>
#include <string.h>

int field[52][52] = {0};
int visited[52][52] = {0};
// moveX,Y[4] = {위, 아래, 왼, 오};
int moveX[4] = {-1, 1, 0, 0};
int moveY[4] = {0, 0, -1, 1};

int findEarthwarmNum(int x, int y, int earthwarmNum){
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++){
        int newX = x + moveX[i];
        int newY = y + moveY[i];
        if (field[newX][newY] == 1 && visited[newX][newY] == 0)
            findEarthwarmNum(newX, newY, earthwarmNum);
        else
            continue;
    }
    earthwarmNum++;
    return earthwarmNum;

}

int main(){
    int T, M, N, K, x, y;
    scanf("%d", &T);
    
    for(int tc = 0; tc < T; tc++){
        for(int i = 0; i < 52; i++){
            memset(field[i], 0, sizeof(int) * 52);
            memset(visited[i], 0, sizeof(int) * 52);
        }
        scanf("%d %d %d", &M, &N, &K);
        for (int i = 0; i < K; i++){
            scanf("%d %d", &x, &y);
            field[x + 1][y + 1] = 1;
        }

        int earthwarmNum = 0;
        for (x = 1; x < 51; x++){
            for(y = 1; y < 51; y++){
            if (field[x][y] == 1 && field[x - 1][y] == 0 && field[x][y - 1] == 0 && visited[x][y] == 0)
                earthwarmNum = findEarthwarmNum(x, y, earthwarmNum);
            }
        }
        printf("%d\n", earthwarmNum);
    }

    return 0;
}                                                                                                                                               
