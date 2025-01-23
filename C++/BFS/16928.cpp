#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int N(0), M(0);
map<int, int> go;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<pair<int, int>> que;
    vector<bool> visited(100, false);   // 존재의 이유: 메모리 초과때문이 큼

    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        int a(0), b(0);
        cin >> a >> b;
        go[a] = b;
    }

    que.push({1, 0});
    visited[1] = true;

    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        if (cur.first == 100) 
        {
            cout << cur.second << '\n';
            return 0;
        }

        for (int i = 1; i <= 6; i++)
        {
            int iNext = cur.first + i;

            if (iNext > 100)
                continue;

            if (go.count(iNext))
                iNext = go[iNext];

            if (!visited[iNext])
            {
                visited[iNext] = true;
                que.push({iNext, cur.second + 1});
            }
        }
    }

    return 0;
}