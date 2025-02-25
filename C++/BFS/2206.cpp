#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int arr[1001][1001];
bool visited[1001][1001][2]; // [x][y][0]: 벽을 안 부순 경우, [x][y][1]: 벽을 부순 경우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Node
{
    int x, y, dist, broken;
};

int BFS() {
    queue<Node> que;
    que.push({0, 0, 1, 0}); // 시작 위치도 경로 수에 포함하기로 했음.
    visited[0][0][0] = true;

    while (!que.empty()) {
        Node cur = que.front();
        que.pop();

        if (cur.x == N - 1 && cur.y == M - 1) 
            return cur.dist;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {   //벽인 경우와 벽이 아닌 경우로 나뉨
                if (arr[nx][ny] == 0 && !visited[nx][ny][cur.broken]) {  // 벽이 아니고, 방문한 적 없는 경우
                    visited[nx][ny][cur.broken] = true;       // 내가 지금 부수는 행위를 수행했는지 안했는지를 다음 위치로 넘겨준다.
                    que.push({nx, ny, cur.dist + 1, cur.broken});
                }
                else if (arr[nx][ny] == 1 && cur.broken == 0) {  // 벽이지만 아직 부순 적이 없을 경우, 부수고 이동
                    visited[nx][ny][1] = true;  // 부수는 행위를 행하지 않았어야 현재위치에서 broken이 0이 된다.
                    que.push({nx, ny, cur.dist + 1, 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    cout << BFS() << '\n';
    return 0;
}
