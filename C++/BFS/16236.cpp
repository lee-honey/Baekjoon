#include <iostream>
#include <queue>

using namespace std;

int N(0);
int arr[21][21];
queue<pair<pair<int, int>, int>> que;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int sx(0), sy(0); // 상어 위치
int sz(2); // 상어크기
bool canEat(true), eat(false);
int cnt(0); // 먹은개수
int result(0);

void BFS(int x, int y) // 한마리를 먹기까지의 과정
{
    bool visited[22][22] = {false,};
    que.push({{x, y}, 0});
    arr[x][y] = 0; // arr이 0보다 클경우라는 케이스에서 빼주고싶어서 이렇게 함

    int temp(0);
    while(!que.empty())
    {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int cnt = que.front().second;

        if(arr[x][y] > 0 && arr[x][y] < sz && temp == cnt) // 같은시간이걸린물고기들중
        {
            if(sx > x || (sx == x && sy > y)) // 이 조건에 해당하는 물고기라면면
            {
                sx = x;
                sy = y; // 그 위치로 상어위치를 갱신(arr를 변화시키지 않아 가능)
                continue;
            }
        }
        que.pop();

        for(int i = 0; i < 4; i++) // 상어 위치로부터 네방향 탐색
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]
            && arr[nx][ny] <= sz)
            {
                if(arr[nx][ny] > 0 && arr[nx][ny] < sz && !eat) // 먹을수있는물고기의 위치라면
                {  // 너비우선이기에 가장 빨리 먹을수있는 물고기의 의미를 가짐.
                    eat = true; // 먹었다고 세팅해주고
                    sx = nx;
                    sy = ny; // 상어위치옮김
                    temp = cnt + 1; // 한마리먹는데 걸린 시간
                    result += temp; // 결과에 더해줘.
                }
                else
                {
                    que.push({{nx, ny}, cnt + 1}); // 가장가까운 4방향에 물고기 없을 경우 전진.
                    visited[nx][ny] = true; // 해당위치를 True로 만듦
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 9)
            {
                sx = i;
                sy = j;
            }
        }
    }

    while(canEat) // 더이상 먹을 수 없을 때까지 BFS를 반복
    {
        BFS(sx, sy); // 먹었는지 안먹었는지 결과를 받음
        if(eat) // 먹었을경우
        {
            eat = false; // 먹은상태초기화화
            cnt++; // 먹은개수늘림
            if(cnt == sz) // 먹은개수와 상어크기가 같으면
            {
                sz++; // 상어크기를 늘리고
                cnt = 0; // 먹은개수를 초기화
            }
        }
        else // 먹지 못했을 경우
            canEat = false; // while문 종료
    }

    cout << result << '\n';

    return 0;
}
