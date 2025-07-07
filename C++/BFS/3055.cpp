#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;

int R, C;
char arr[51][51];
queue<pair<int, pair<int, int>>> que;
deque<pair<int, int>> water;
bool visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            arr[i][j] = str[j];
            if (arr[i][j] == 'S') {
                que.push({0, {i, j}});
                visited[i][j] = true;
                arr[i][j] = '.';
            }
            if (arr[i][j] == '*')
                water.push_back({i, j});
        }
    }

    while (!que.empty()) {
        int waterSize = water.size();
        for (int i = 0; i < waterSize; i++) {
            int wx = water.front().first;
            int wy = water.front().second;
            water.pop_front();
            for (int d = 0; d < 4; d++) {
                int nx = wx + dx[d];
                int ny = wy + dy[d];
                if (0 <= nx && nx < R && 0 <= ny && ny < C && arr[nx][ny] == '.') {
                    arr[nx][ny] = '*';
                    water.push_back({nx, ny});
                }
            }
        }

        int size = que.size(); // 큐에 들어있는 위치할수있는 고슴도치 위치에 대해 전부 이동을 수행시켜야 함
        for (int i = 0; i < size; i++) {
            int depth = que.front().first;
            int cx = que.front().second.first;
            int cy = que.front().second.second;
            que.pop();

            if (arr[cx][cy] == 'D') {
                cout << depth << '\n';
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (0 <= nx && nx < R && 0 <= ny && ny < C
                    && !visited[nx][ny]
                    && (arr[nx][ny] == '.' || arr[nx][ny] == 'D')) {
                    visited[nx][ny] = true;
                    que.push({depth + 1, {nx, ny}});
                }
            }
        }
    }

    cout << "KAKTUS" << '\n';
    return 0;
}
