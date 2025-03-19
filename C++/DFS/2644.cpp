#include <iostream>
#include <vector>

using namespace std;

int N(0);
int A(0), B(0);
int M(0);
vector<int> arr[101];
bool visited[101] = {false,};
int ans(0);

void DFS(int X, int depth)
{
    visited[X] = true;

    if(X == B)
    {
        ans = depth;
        return;
    }

    for(int i = 0; i < arr[X].size(); i++)
    {
        if(visited[arr[X][i]] == false)
            DFS(arr[X][i], depth + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> A >> B;
    cin >> M;
    while(M--)
    {
        int X(0), Y(0);
        cin >> X >> Y;
        arr[X].push_back(Y);
        arr[Y].push_back(X);
    }

    DFS(A, 0);
    if(ans == 0)
        ans = -1;
    cout << ans << '\n';

    return 0;
}