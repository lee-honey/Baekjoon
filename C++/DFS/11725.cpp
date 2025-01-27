#include <iostream>
#include <vector>

// 양방향 그래프연결 문제임.

using namespace std;

int N(0);
int arr[100001];
bool visited[100001];
vector<int> v[100001];

void DFS(int k)
{
    visited[k] = true;
    for(int i = 0; i < v[k].size(); i++)
    {
        int next = v[k][i];
        if(!visited[next])
        {
            arr[next] = k; // 부모세팅
            DFS(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int a(0), b(0);
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i = 2; i <= N; i++)
        cout << arr[i] << '\n';

    return 0;
}