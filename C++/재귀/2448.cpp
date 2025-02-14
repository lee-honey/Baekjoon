#include <iostream>

using namespace std;

int N(0);
char map[3072][6144];

void DFS(int x, int y, int n)
{
    if(n == 3)
    {
        map[y][x] = '*';
        map[y + 1][x - 1] = '*';
        map[y + 1][x + 1] = '*';
        for(int i = x - 2; i <= x + 2; i++)
            map[y + 2][i] = '*';
        return;
    }

    DFS(x, y, n / 2);                           // 위쪽 삼각형
    DFS(x - n / 2, y + n / 2, n / 2);           // 아래 왼쪽 삼각형
    DFS(x + n / 2, y + n / 2, n / 2);           // 아래 오른쪽 삼각형
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 2 * N; j++)
            map[i][j] = ' ';

    DFS(N - 1, 0, N); // 처음에는 맨위꼭대기 * 하나있는곳의 좌표 (n - 1, 0);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 2 * N; j++)
            cout << map[i][j];
        cout << '\n';
    }

    return 0;
}