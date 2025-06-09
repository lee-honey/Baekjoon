#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<char>> grid;
string word;
int cnt = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<bool>> visited;

void DFS(int x, int y, int depth) {
    if (grid[x][y] != word[depth]) return;

    if (depth == N - 1)
    {
        cnt++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            DFS(nx, ny, depth + 1);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    grid.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        string line; 
        cin >> line;
        for (int j = 0; j < N; j++) {
            grid[i][j] = line[j];
        }
    }

    cin >> word;

    visited.assign(N, vector<bool>(N, false));
    cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == word[0])
            {
                visited[i][j] = true;
                DFS(i, j, 0);
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
