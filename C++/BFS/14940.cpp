#include <iostream>
#include <queue>

using namespace std;

int n(0), m(0);
int board[1000][1000];
int dist[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = -1;    // 왜이렇게 초기화? = 맨처음위치부터 시작하여 -1에서 벗어난 기존값과만 비교를 하면서 갱신해야 하며,
            cin >> board[i][j]; // 끝까지 이 값에 닿지 못했다면 그 값을 유지하기에 끝까지 -1이라는 결과를 출력하도록 함임
            if(board[i][j] == 2)    // 시작위치가 잡히는 즉시 queue에 푸쉬한다.
            {
                que.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    while(!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if(dist[nx][ny] != -1)
                continue;
            if(board[nx][ny] == 0)
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1; // dist에 누적된 깊이를 갱신해서 기록
            que.push(make_pair(nx, ny));
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}