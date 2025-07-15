#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int N(0), M(0), K(0);
int arr[101][101];
bool bIsVisited[101][101];
queue<pair<int, int>> que;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int>> vec;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        int x(0), y(0);
        cin >> x >> y;
        arr[x - 1][y - 1] = 1;
        vec.push_back({x - 1, y - 1});
    }

    for(int j = 0; j < vec.size(); j++)
    {
        int x = vec[j].first;
        int y = vec[j].second;
        if(bIsVisited[x][y] == false)
        {
            que.push({x, y});
            bIsVisited[x][y] = true;
        }

        int size(1);
        while(!que.empty())
        {
            int cx = que.front().first;
            int cy = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(0 <= nx && nx < N && 0 <= ny && ny < M 
                && bIsVisited[nx][ny] == false && arr[nx][ny] == 1)
                {
                    bIsVisited[nx][ny] = true;
                    que.push({nx, ny});
                    size++;
                }
            }
        }
        ans = max(ans, size);
    }

    cout << ans << '\n';

    return 0;
}