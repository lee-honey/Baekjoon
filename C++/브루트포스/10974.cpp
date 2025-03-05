#include <iostream>
#include <string>

using namespace std;

int N(0);
bool visited[9] = {false, };
int res[9] = {0,};

void DFS(int depth, int n)
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
        if(visited[i] == false)
        {
            res[depth] = i; 
            visited[i] = true;
            DFS(depth + 1, i);
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

    DFS(0, 0);

    return 0;
}