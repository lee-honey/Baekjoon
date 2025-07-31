#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), M(0), R(0);
vector<vector<int>> graph;
vector<bool> bIsVisited;
vector<int> ans;
int depth(0);

void DFS(int node)
{
    bIsVisited[node] = true;
    ans[node] = ++depth;

    for(int i = 0; i < graph[node].size(); i++)
    {
        int cur = graph[node][i];
        if(bIsVisited[cur] == false)
            DFS(cur);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    bIsVisited.resize(N + 1);
    ans.resize(N + 1);
    graph.resize(N + 1);

    for(int i = 0; i < M; i++)
    {
        int u(0), v(0);
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0; i < N; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(R);

    for(int i = 1; i <= N; i++)
        cout << ans[i] << "\n";

    return 0;
}