#include <iostream>

using namespace std;

int N(0), M(0);
int arr[10] = {0,};
bool bIsVisited[10] = {false,};

void DFS(int num, int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++)
    {
        if(bIsVisited[i] == false)
        {
            bIsVisited[i] = true;
            arr[depth] = i;
            DFS(i + 1, depth + 1);
            bIsVisited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    DFS(1, 0);

    return 0;
}