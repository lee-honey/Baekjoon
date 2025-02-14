#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n(0);
int s(0), e(0), d(0);
vector<bool> vecVisited;
vector<pair<int, int>> node[10001];
int maxDist(-1), maxNode(0);

void DFS(int now, int dist)
{
    vecVisited[now] = true;
    if(maxDist < dist)
    {
        maxDist = dist;
        maxNode = now;
    }

    for(int i = 0; i < node[now].size(); i++)
    {
        if(vecVisited[node[now][i].first])
            continue;
        DFS(node[now][i].first, dist + node[now][i].second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vecVisited.resize(n+1);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> s >> e >> d;
        node[s].push_back({e, d});
        node[e].push_back({s, d});
    }
    DFS(1, 0);
    vecVisited.assign(n + 1, 0);
    maxDist = -1;
    DFS(maxNode, 0);
    cout << maxDist << '\n';

    return 0;
}
