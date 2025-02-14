#include <iostream>
#include <string>

using namespace std;

int R(0), C(0);
int maxCnt(0);
bool bVisited[26];
char map[20][20];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void DFS(int y, int x, int cnt)
{
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C)  continue;
        if(bVisited[map[ny][nx] - 'A'] == true)     continue;

        bVisited[map[ny][nx] - 'A'] = true;
        maxCnt = (maxCnt > cnt + 1) ? maxCnt : cnt + 1;
        DFS(ny, nx, cnt + 1);
        bVisited[map[ny][nx] - 'A'] = false;    // 이렇게해줘야 백트래킹이 됨
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int y = 0; y < R; y++)
    {
        string str;
        cin >> str;
        for(int x = 0; x < C; x++)
            map[y][x] = str[x];
    }

    bVisited[map[0][0] - 'A'] = true;
    maxCnt = 1;
    DFS(0, 0, 1);

    cout << maxCnt << '\n';

    return 0;
}
