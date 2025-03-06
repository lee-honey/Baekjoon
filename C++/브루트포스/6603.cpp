#include <iostream>

using namespace std;

int k(0);
int arr[14] = {0,};
bool visited[14] = {false,};

void DFS(int depth, int n)
{
    if(depth == 6)
    {
        for(int i = 0; i < k; i++)
        {
            if(visited[i] == true)
                cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = n; i < k; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            DFS(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> k;
        if(k == 0)  break;

        for(int i = 0; i < k; i++)
            cin >> arr[i];

        DFS(0, 0);
        cout << '\n';
    }

    return 0;
}