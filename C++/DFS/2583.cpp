#include <iostream>
#include <queue>

using namespace std;

int M(0), N(0), K(0);
int arr[101][101] = {0,};
int depth(0);
int ans(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[101][101] = {false,};
priority_queue<int, vector<int>, greater<int>> que;

void DFS(int y, int x, bool visited[101][101])
{
    visited[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= ny && ny < M && 0 <= nx && nx < N
        && arr[ny][nx] == 0 && visited[ny][nx] == false)
        {
            depth++;
            DFS(ny, nx, visited);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    while(K--)
    {
        int x1(0), y1(0), x2(0), y2(0);
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++)
        {
            for(int j = x1; j < x2; j++)
                arr[i][j] = 1;
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == 0 && visited[i][j] == false)
            {
                depth = 1;
                DFS(i, j, visited);
                que.push(depth);
            }
        }
    }

    cout << que.size() << '\n';
    while(!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }

    return 0;
}