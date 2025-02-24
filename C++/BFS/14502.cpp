#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N(0), M(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[8][8];
int tempArr[8][8];
vector<pair<int, int>> vecEmpty;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                vecEmpty.push_back({i, j});
        }
    }

    for(int i = 0; i < vecEmpty.size() - 2; i++)
    {
        for(int j = i + 1; j < vecEmpty.size() - 1; j++)
        {
            for(int k = j + 1; k < vecEmpty.size(); k++)
            {
                queue<pair<int, int>> que;

                for(int a = 0; a < N; a++)
                {
                    for(int b = 0; b < M; b++)
                    {
                        tempArr[a][b] = arr[a][b];
                        if(arr[a][b] == 2)
                            que.push({a, b});
                    }
                }

                tempArr[vecEmpty[i].first][vecEmpty[i].second] = 1;
                tempArr[vecEmpty[j].first][vecEmpty[j].second] = 1;
                tempArr[vecEmpty[k].first][vecEmpty[k].second] = 1;

                // BFS
                while(!que.empty())
                {
                    int curX = que.front().first;
                    int curY = que.front().second;
                    que.pop();

                    int nx(0), ny(0);
                    for(int a = 0; a < 4; a++)
                    {
                        nx = curX + dx[a];
                        ny = curY + dy[a];
                        if(0 <= nx && nx < N && 0 <= ny && ny < M && tempArr[nx][ny] == 0)
                        {
                            tempArr[nx][ny] = 2;
                            que.push({nx, ny});
                        }
                    }
                }

                int iTemp(0);
                for(int a = 0; a < N; a++)
                    for(int b = 0; b < M; b++)
                        if(tempArr[a][b] == 0)
                            iTemp++;

                if(ans < iTemp)
                    ans = iTemp;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}