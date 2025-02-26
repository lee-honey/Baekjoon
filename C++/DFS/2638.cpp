#include <iostream>
#include <queue>

using namespace std;

int N(0), M(0);
int arr[101][101];
int ans(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> que;

void DFS(int x, int y)
{
    if(arr[x][y] == 0) // 더 깊이 내려가야하면 아래까지 실행하고 마지막에 return;
        arr[x][y] = -1;
    else                // 깊이 내려갈 조건이 되지 않으면 즉시 return;
        return;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < N && 0 <= ny && ny < M)
            DFS(nx, ny);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    DFS(0, 0);
    while(true)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(arr[i][j] == 1)
                {
                    int cnt(0);
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(0 <= nx && nx < N && 0 <=ny && ny < M && arr[nx][ny] == -1)
                            cnt++;
                    }
                    if(cnt >= 2)
                        que.push({i, j});
                }
            }
        }

        if(que.empty())
            break;

        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;

            arr[x][y] = -1;     // 치즈를 외부공기로 바꿈

            que.pop();

            for(int i = 0; i < 4; i++) // 치즈 내부공기를 외부공기로 바꿈
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < N && 0 <=ny && ny < M && arr[nx][ny] == 0) 
                    DFS(nx, ny);  // 내부공기는 치즈로 둘러쌓여있을거니까 여기서 검사해도 무관
            }
        }
        ans++;
    }

    cout << ans <<'\n';

    return 0;
}