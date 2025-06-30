#include <iostream>
#include <queue>
#define INF 2147483647

using namespace std;

int N(0), M(0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[100001];
int values[100001];
int st(0), ed(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A(0), B(0), C(0);
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    cin >> st >> ed;


    for(int i = 0; i < 100001; i++)
        values[i] = INF;

    pq.push({0, st});
    values[st] = 0;

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(values[now] < dist)
            continue;

        for(int i = 0; i < graph[now].size(); i++)
        {
            int nextDist = dist + graph[now][i].second;
            int nextNode = graph[now][i].first;
            if(nextDist < values[nextNode])
            {
                values[nextNode] = nextDist;
                pq.push({values[nextNode], nextNode});
            }
        }
    }

    cout << values[ed] << '\n';

    return 0;
}