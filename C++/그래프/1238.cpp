#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000

using namespace std;

int N(0), M(0), X(0);
vector<pair<int, int>> graph[1001];
int value[1001];
int ans[1001];
int res(0);

void Dijkstra(int x)
{
    for (int j = 1; j <= N; j++)
    value[j] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    value[x] = 0;

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(value[cur] < dist) continue;

        for(int k = 0; k < graph[cur].size(); k++)
        {
            int nextDist = graph[cur][k].second;
            int nextNode = graph[cur][k].first;

            if(dist + nextDist < value[nextNode])
            {
                value[nextNode] = dist + nextDist;
                pq.push({value[nextNode], nextNode});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++)
    {
        int s(0), e(0), d(0);
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
    }

    for(int i = 1; i <= N; i++)
    {
        Dijkstra(i);
        ans[i] = value[X];
    }

    Dijkstra(X);

    for(int i = 1; i <= N; i++)
        ans[i] += value[i];

    for(int i = 1; i <= N; i++)
        if(res < ans[i]) res = ans[i];

    cout << res << '\n';

    return 0;
}