#include <iostream>
#include <algorithm>

using namespace std;

int N(0);
int W[11][11] = {0,};
bool visited[11] = {false,};
int arr[11] = {0,};
int ans(2147483647);

void DFS(int depth)
{
    if(depth == N)
    {
        int sum(0);
        for(int i = 1; i < N; i++)
        {
            if(W[arr[i - 1]][arr[i]] == 0) // 경로가 없는 경우를
                return;
            sum += W[arr[i - 1]][arr[i]];
        }
        if(W[arr[N - 1]][arr[0]] != 0) // 제외할 것
        {
            sum += W[arr[N - 1]][arr[0]];
            ans = min(sum, ans);
        }
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            arr[depth] = i;
            DFS(depth + 1);
            visited[i] = false;
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
        for(int j = 0; j < N; j++)
            cin >> W[i][j];

    DFS(0);

    cout << ans << '\n';

    return 0;
}