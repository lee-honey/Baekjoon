//0. 최초 cnt는 1
//1. board 2차원 배열 초기화
//2. x,y 정보를 담는 q 배열에 첫 x,y인 0, 0을 넣고 push
//3.bfs의 while문에서 맨 처음 x,y를 할당해주고 pop
//4.for문을 돌며 x, y에 각각 dx, dy를 더한 값을 nx, ny로 할당
//5. board[nx][ny]값이 테이블 내에 있고, 방문한 적 없으며, 1인 경우 해당 nx, ny를 q에 push
//6.q while문이 실행될 때마다 cnt를 증가시켜줌
//7. nx, ny가 N - 1, M - 1이 되는 경우에 최초로 해당하는 위치에 도달한 것이므로 이 즉시 bfs문을 멈추고 cnt값을 return

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int board[101][101];
bool isVisited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<pair<int, int>, int>> q; //깊이를 저장해주려면 쌍pair로 구현해야 합니다.
int cnt = 0;

void bfs(void)
{
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int tempSize = q.front().second;
        q.pop();
        if(x == N - 1 && y == M - 1)
        {
            cnt = tempSize;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(isVisited[nx][ny]) continue;
            if(board[nx][ny] == 1)
            {
                q.push({{nx, ny}, tempSize + 1}); //같은 깊이에 있는 큐 요소들은 같은 깊이값을 갖게 함.
                isVisited[nx][ny] = true;
            }
        }
        cnt++;
    }
}

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = temp[j] - '0';
        }
    }
    q.push({{0,0}, 1});
    isVisited[0][0] = true;
    bfs();
    cout << cnt << '\n';
    return 0;
}