#include <iostream>
#include <vector>
#include <queue>
#include <utility> // pair ����� ���� ���

using namespace std;

int n; // �̷��� ũ��
vector<int> maze(1001, 0); // �̷��� �� ĭ�� ���� ���ڸ� �����ϴ� ����
vector<bool> visited(1001, false); // �湮 ���� ���� ����

// �̷� Ž���ϸ� �ּ� ���� Ƚ���� ����ϴ� �Լ�
int calSol(){
    int rst = -1; // �̷��� ������ ������ �� ���� ��� -1
    queue<pair<int, int> > q; // Q. <int, int> �ڿ� ���� �� ������?
    // pair�� idx0�� �ε�����, idx1�� �ش� idx���� �����ϴµ� �ʿ��� ���� Ƚ��
    // index, the number of jump
    q.push(make_pair(0, 0));
    // Q. ������ queue<pair<int, int>> q��� ����µ�,  make_pair�̶�� �� ������ϴ°�?
    while(!q.empty()){
        int cur_i = q.front().first; // cur_i�� ���� �ε���
        int cur_c = q.front().second; // cur_c�� ���� ���� Ƚ��
        q.pop();
        if(cur_i >= n) // �̷� ���� �Ѿ�� ���
            continue;
        if(cur_i == n - 1){ // ���� idx�� �̷��� ���� ��
            rst = cur_c; // rst�� ���� Ƚ��!
            break;
        }
        //insert biggest value -> to calculate minimum number of jump
        //biggest value means jumping to furthest maze
        for (int i = maze[cur_i]; i > 0; i--) // Q. �� ū ������ -- �ϴ°�? ++�� �ö󰡸� �ȵǳ�?
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