#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N(0), L(0), R(0);
int arr[51][51] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool bIsVisited[51][51] = {false,};
int ans(0);
vector<pair<int, int>> open;

bool BFS(int x, int y)
{
    if(bIsVisited[x][y] == true) return false;

    open.clear();
    queue<pair<int, int>> que;
    que.push({x, y});
    bIsVisited[x][y] = true;
    open.push_back({x, y});

    while(!que.empty())
    {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int diff = abs(arr[cx][cy] - arr[nx][ny]);
            if(0 <= nx && nx < N && 0 <= ny && ny < N && bIsVisited[nx][ny] == false
            && L <= diff && diff <= R)
            {
                que.push({nx, ny});
                bIsVisited[nx][ny] = true;
                open.push_back({nx, ny});
            }
        }
    }

    return open.size() > 1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(true)
    {
        memset(bIsVisited, false, sizeof(bIsVisited));
        bool flag = false;
        for(int i = 0; i < N; i++) // 모든 노드에 대해 검사
        {
            for(int j = 0; j < N; j++)
            {
                if(BFS(i, j) == true)
                {
                    flag = true; // 한번이라도 플래그가 나오면
                    int sum(0);
                    for(auto& p : open){
                        sum += arr[p.first][p.second];
                    }
                    int avg = sum / open.size();
                    for(auto& p : open){
                        arr[p.first][p.second] = avg;
                    }
                }
            }
        }
        if(!flag) break; // while문을 재실행하지만 안나올경우 즉시 종료
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
