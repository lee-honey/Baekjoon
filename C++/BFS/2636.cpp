#include <iostream>
#include <queue>

using namespace std;

int N(0), M(0);
int arr[101][101] = {0,};
bool bIsVisitied[101][101] = {false,};
queue<pair<int, int>> que;
queue<pair<int, int>> temp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans(0);
int cnt(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    que.push({0, 0});
    bIsVisitied[0][0] = true;
    
    while(!que.empty()) // 첫번째 while문: 이 내부의 치즈 밖 상황에서 일련의 BFS를 거칠 때마다 한번 실행행
    {
        ans = que.size();
        while(!que.empty()) // 두번째 while문: 각자의 상태에서 지나갈 수 있는 공간에 대해 BFS를 끝냄
        {
            int curX = que.front().first;
            int curY = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
                {
                    if(bIsVisitied[nextX][nextY] == false && arr[nextX][nextY] == 1)
                        temp.push({nextX, nextY});
                    if(bIsVisitied[nextX][nextY] == false && arr[nextX][nextY] == 0)
                        que.push({nextX, nextY});
                    bIsVisitied[nextX][nextY] = true;
                }
            }
        }
        while(!temp.empty()) // 세번째 while문: 치즈 -> 빈공간으로 변한 공간에 대해 que에 집어넣어 다시 bfs 수행
        {
            que.push(temp.front());
            temp.pop();
        }
        cnt++;
    }
    
    cout << cnt - 1 << '\n';
    cout << ans << '\n';
    return 0;
}