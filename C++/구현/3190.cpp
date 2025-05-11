#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
int ans = 0;
int arr[101][101] = {0,};
queue<pair<int, char>> que;
deque<pair<int, int>> snake;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        que.push({X, C});
    }

    snake.push_back({0, 0});    
    int cx(0), cy(0), cd(0);

    while(true)
    {
        ans++;
        int nx = cx + dx[cd];
        int ny = cy + dy[cd];   // 선전진
        if(0 <= nx && nx < N && 0 <= ny && ny < N)  // 전진한곳 위치가 벽이거나 자신의 몸통인 경우
        {
            for(int i = 0; i < snake.size(); i++)
            {
                if(nx== snake[i].first && ny == snake[i].second)
                {
                    cout << ans << '\n';
                    return 0;
                }
            }
        }
        else
            break;

        snake.push_front({nx, ny}); // 전진한 위치를 실제로 갱신
        cx = nx;
        cy = ny;
        if (arr[nx][ny] == 1)
            arr[nx][ny] = 0;
        else
            snake.pop_back();

        if (!que.empty() && que.front().first == ans) // 후방향전환
        {
            char turn = que.front().second;
            if (turn == 'L')
                cd = (cd + 1) % 4;
            else if (turn == 'D')
                cd = (cd + 3) % 4;
            que.pop();
        }
    }

    cout << ans << '\n';
    return 0;
}
