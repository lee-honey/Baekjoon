#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n(0), m(0);
bool bIsVisited[501][501] = {false,};
int arr[501][501] = {0,};
int ansNum(0), ansSize(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(int x, int y)
{
    queue<pair<int, int>> que;
    int temp(0);
    que.push({x, y});
    bIsVisited[x][y] = true;
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        temp++;
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
            {
                if(bIsVisited[nextX][nextY] == false && arr[nextX][nextY] == 1)
                {
                    que.push({nextX, nextY});
                    bIsVisited[nextX][nextY] = true;
                }
            }
        }
    }
    ansSize = max(temp, ansSize);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1 && bIsVisited[i][j] == false)
            {
                BFS(i, j);
                ansNum++;
            }
        }
    }

    cout << ansNum << '\n';
    cout << ansSize << '\n';

    return 0;
}