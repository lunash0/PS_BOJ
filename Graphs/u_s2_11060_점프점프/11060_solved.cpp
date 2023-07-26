#include <iostream>
#include <vector>
#include <queue>
#include <utility> // pair 사용을 위한 헤더

using namespace std;

int n; // 미로의 크기
vector<int> maze(1001, 0); // 미로의 각 칸에 적힌 숫자를 저장하는 벡터
vector<bool> visited(1001, false); // 방문 여부 저장 벡터

// 미로 탐색하며 최소 점프 횟수를 계산하는 함수
int calSol(){
    int rst = -1; // 미로의 끝점에 도달할 수 없는 경우 -1
    queue<pair<int, int> > q; // Q. <int, int> 뒤에 띄어쓰기 한 이유는?
    // pair의 idx0은 인덱스를, idx1은 해당 idx까지 도달하는데 필요한 점프 횟수
    // index, the number of jump
    q.push(make_pair(0, 0));
    // Q. 위에서 queue<pair<int, int>> q라고 해줬는데,  make_pair이라고 꼭 해줘야하는가?
    while(!q.empty()){
        int cur_i = q.front().first; // cur_i는 현재 인덱스
        int cur_c = q.front().second; // cur_c는 현재 점프 횟수
        q.pop();
        if(cur_i >= n) // 미로 끝을 넘어가는 경우
            continue;
        if(cur_i == n - 1){ // 현재 idx가 미로의 끝일 때
            rst = cur_c; // rst는 현재 횟수!
            break;
        }
        //insert biggest value -> to calculate minimum number of jump
        //biggest value means jumping to furthest maze
        for (int i = maze[cur_i]; i > 0; i--) // Q. 왜 큰 값부터 -- 하는가? ++로 올라가면 안되나?
        {
            if (cur_i + i < n && !visited[cur_i + i])
            {
                visited[cur_i + i] = true;
                q.push(make_pair(cur_i + i, cur_c + 1));
            }
        }
    }
    return rst;
}

int main(){

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }

    cout << calSol() << "\n";

    return 0;
}