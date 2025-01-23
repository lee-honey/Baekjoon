#include <iostream>
#include <queue>

using namespace std;

int M(0), N(0), H(0);
int tomato[100][100][100];
int dest[100][100][100];
int day = 0;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    queue<pair<pair<int, int>, int>> que;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1)
                    que.push({{i,j},k});
                else if(tomato[i][j][k] == 0)
                    dest[i][j][k] = -1;
            }
        }
    }

    while(!que.empty())
    {
        pair<pair<int, int>, int> cur = que.front();
        que.pop();
        for(int i = 0; i < 6; i++)
        {
            int nz = cur.first.first + dz[i];
            int nx = cur.first.second + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if(dest[nz][nx][ny] >= 0) continue;
            dest[nz][nx][ny] = dest[cur.first.first][cur.first.second][cur.second] + 1;
            que.push({{nz,nx},ny});
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(dest[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }
                day = (day > dest[i][j][k]) ? day : dest[i][j][k];
            }
        }
    }

    cout << day;

    return 0;
}