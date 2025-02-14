#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int value[20001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++)
        value[i] = INF;

    for (int i = 0; i < E; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
    }

    pq.push({0, K});
    value[K] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (value[now] < dist) continue;

        for (auto next : graph[now])
        {
            int nextNode = next.first;
            int nextDist = next.second;

            if (dist + nextDist < value[nextNode])
            {
                value[nextNode] = dist + nextDist;
                pq.push({value[nextNode], nextNode});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (value[i] == INF)
            cout << "INF\n";
        else
            cout << value[i] << '\n';
    }

    return 0;
}
