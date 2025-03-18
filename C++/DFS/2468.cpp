#include <iostream>
#include <queue>

using namespace std;

int N(0);
int arr[101][101] = {0,};
bool bIsSink[101][101] = {false,};
int minWater(102);
priority_queue<int, vector<int>, greater<int>> que;
int bIsInQue[101] = {false};
int ans(0);

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y, bool visited[101][101])
{
    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < N && 0 <= ny && ny < N
            && bIsSink[nx][ny] == false && visited[nx][ny] == false)
        DFS(nx, ny, visited);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if(bIsInQue[arr[i][j]] == false)
            {
                que.push(arr[i][j]);
                bIsInQue[arr[i][j]] = true;
            }
        }
    }

    while(!que.empty())
    {
        int land(0);
        bool visited[101][101] = {false,};
        int water = que.top();
        que.pop();

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(arr[i][j] < water)
                    bIsSink[i][j] = true; // 여기 물에 잠김처리
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(bIsSink[i][j] == false && visited[i][j] == false)
                {
                    land++;
                    DFS(i, j, visited);
                }
            }
        }
        if(ans < land)
            ans = land;
    }
    cout << ans << '\n';
}