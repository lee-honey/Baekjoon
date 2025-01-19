#include <iostream>
#include <queue>

using namespace std;

int N = 0, M = 0;
int res = 0;
char map[600][600];
bool visited[600][600];
pair<int, int> iPos; //도연이 위치

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void BFS()
{
    queue<pair<int, int>> q;
    q.push(iPos);
    visited[iPos.first][iPos.second] = true;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            pair<int, int> next = { cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
                continue;

            if(map[next.first][next.second] == 'X')
                continue;

            if(visited[next.first][next.second] == true)
                continue;

            if(map[next.first][next.second] == 'P')
                res++;

            q.push(next);
            visited[next.first][next.second] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> map[y][x];
            if(map[y][x] == 'I')
            {
                iPos.first = y;
                iPos.second = x;
            }
        }
    }

    BFS();

    if(res == 0) 
        cout << "TT" << '\n';
    else
        cout << res << '\n';

    return 0;
}