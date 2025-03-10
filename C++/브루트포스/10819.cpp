#include <iostream>

using namespace std;

int N(0);
int A[9] = {0,};
bool visited[9] = {false,};
int ans(0);

void DFS(int depth, int n, int res)
{
    if(depth == N)
    {
        ans = (res > ans) ? res : ans;
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            DFS(depth + 1, i, res + abs(A[n] - A[i]));
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
        cin >> A[i];
    
    for(int i = 0; i < N; i++)
    {
        visited[i] = true;
        DFS(1, i, 0);
        visited[i] = false;
    }

    cout << ans << '\n';

    return 0;
}