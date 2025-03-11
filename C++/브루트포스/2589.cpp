// 브루트포스 + 백트래킹

#include <iostream>
#include <queue>

using namespace std;

int row(0), col(0);
char arr[51][51];
queue<pair<int, pair<int, int>>> que;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans(0);

void BFS(int i, int j)
{
    bool visited[51][51] = {false,};
    if(arr[i][j] == 'L')
    {
        que.push({0, {i, j}});
        visited[i][j] = true;
        while(!que.empty())
        {
            int depth = que.front().first;
            int curX = que.front().second.first;
            int curY = que.front().second.second;
    
            if(depth > ans)
                ans = depth;
    
            que.pop();
    
            for(int k = 0; k < 4; k++)
            {
                int nx = curX + dx[k];
                int ny = curY + dy[k];
                if(0 <= nx && nx < row && 0 <= ny && ny < col && arr[nx][ny] == 'L'
                && visited[nx][ny] == false)
                {
                    visited[nx][ny] = true;
                    que.push({depth + 1, {nx, ny}});
                }
            }
        }
   }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;

    for(int i = 0; i < row; i++)
    {
        string str = "";
        cin >> str;
        for(int j = 0; j < col; j++) // 배열에 집어넣어어
            arr[i][j] = str[j];
    }

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            BFS(i, j);

    cout << ans << '\n';

    return 0;
}