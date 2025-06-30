#include <iostream>

using namespace std;

int     R(0), C(0), K(0);
int     arr[5][5] = {0,};
bool    bIsVisited[5][5] = {false,};
int     sx(0), sy(0), ex(0), ey(0);
int     dx[4] = {0, 0, -1, 1};
int     dy[4] = {-1, 1, 0, 0};
int     ans(0);

void BackTracking(int x, int y, int depth)
{
    if(x == ex && y == ey)
    {
        if(depth == K)
            ++ans;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < R && 0 <= ny && ny < C 
            && arr[nx][ny] == 0 && bIsVisited[nx][ny] == false)
        {
            bIsVisited[nx][ny] = true;
            BackTracking(nx, ny, depth + 1);
            bIsVisited[nx][ny] = false;
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;
    sx = R - 1;
    sy = 0;
    ex = 0;
    ey = C - 1;

    for(int i = 0; i < R; i++)
    {
        string str = "";
        cin >> str;

        for(int j = 0; j < C; j++)
        {
            if(str[j] == 'T')
                arr[i][j] = 1;
        }
    }

    bIsVisited[sx][sy] = true;
    BackTracking(sx, sy, 1);

    cout << ans << '\n';

    return 0;
}