#include <iostream>
#include <queue>

using namespace std;

int R(0), C(0), T(0);
int room[51][51];
int ans(0);

void Spread()
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    queue<pair<int, pair<int, int>>> que;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(room[i][j] > 0)
                que.push({room[i][j] / 5, {i, j}});
        }
    }

    while(!que.empty())
    {
        int curDust = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;

        que.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < R && 0 <= ny && ny < C && room[nx][ny] != -1)
            {
                room[nx][ny] += curDust;
                room[x][y] -= curDust;
            }
        }
    }
}

void Circle()
{
    int first(0), second(1);

    int dx1[4] = {0, -1, 0, 1}; // 우상좌하 순
    int dy1[4] = {1, 0, -1, 0};

    for(int i = 0; i < R; i++) // 공기청정기 위치찾기
    {
        if(room[i][0] == -1)
        {
            first = i;
            second = i + 1;
            break;
        }
    }

    int x(first), y(0);
    int prev(0);
    int idx(0);

    while(1)
    {
        int nx(x + dx1[idx]), ny(y + dy1[idx]);
        if(nx < 0 || R <= nx || ny < 0 || C <= ny)
        {
            idx++;
            continue;
        }

        if(nx == first && ny == 0)
            break;

        int cur = room[nx][ny];
        room[nx][ny] = prev;
        prev = cur;
        x = nx;
        y = ny;
    }

    int dx2[4] = {0, 1, 0, -1};
    int dy2[4] = {1, 0, -1, 0};

    x = second;
    y = 0;
    prev = 0;
    idx = 0;

    while(1)
    {
        int nx(x + dx2[idx]), ny(y + dy2[idx]);
        if(nx < 0 || R <= nx || ny < 0 || C <= ny)
        {
            idx++;
            continue;
        }
        if(nx == second && ny == 0)
            break;

        int cur = room[nx][ny];
        room[nx][ny] = prev;
        prev = cur;
        x = nx;
        y = ny;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> room[i][j];
        }
    }

    while(T--)
    {
        Spread();
        Circle();
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(room[i][j] != -1)
                ans += room[i][j];
        }
    }

    cout << ans << '\n';

    return 0;
}