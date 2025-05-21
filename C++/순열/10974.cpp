// 순열 : DFS + 체크리스트

#include <iostream>

using namespace std;

int     N(0);
bool    bIsVisited[9] = {false,};
int     res[9] = {0, };

void DFS(int depth)
{
    if(depth == N)
    {
        for(int i = 0; i < N; i++)
            cout << res[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(bIsVisited[i] == false)
        {
            res[depth] = i;
            bIsVisited[i] = true;
            DFS(depth + 1);
            bIsVisited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS(0);

    return 0;
}