#include <iostream>

using namespace std;

int N(0), M(0);
int arr[9] = {0,};

void DFS(int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        arr[depth] = i;
        DFS(depth + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    DFS(0);

    return 0;
}