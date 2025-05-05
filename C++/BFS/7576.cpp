#include <iostream>
#include <queue>

using namespace std;
int M(0), N(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, pair<int, int>>> que;
int arr[1001][1001] = {0,};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                que.push({0, {i, j}});
        }
    }

    while(!que.empty())
    {
        pair<int, int> cur = que.front().second;
        int depth = que.front().first;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M
                && arr[nx][ny] == 0)
            {
                arr[nx][ny] = 1;
                que.push({depth + 1, {nx, ny}});
            }
        }
        ans = depth;
    }

    bool bIsNotClear = false;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] == 0)
                bIsNotClear = true;
        }
        if(bIsNotClear == true)
        {
            ans = -1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}