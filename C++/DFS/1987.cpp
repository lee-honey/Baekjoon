#include <iostream>
#include <string>

using namespace std;

bool bIsVisited[30] = {false,};

int R(0), C(0);
char arr[21][21];
int ans(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y, int depth)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int idx = arr[nx][ny] - 'A';

        if(0 <= nx && nx < R && 0 <= ny && ny < C && bIsVisited[idx] == false)
        {
            bIsVisited[idx] = true;
            ans = max(ans, depth + 1);
            DFS(nx, ny, depth + 1);
            bIsVisited[idx] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < C; j++)
            arr[i][j] = str[j];
    }

    bIsVisited[arr[0][0] - 'A'] = true;
    ans = 1;
    DFS(0, 0, 1);

    cout << ans << '\n';

    return 0;
}