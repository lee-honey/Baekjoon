#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

int n(0), m(0), st(0), ed(0);
vector<pair<int, int>> graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int values[1001] = {0,}; // 각 노드의 최소거리저장
int routes[1001] = {0,}; // 역추적을 위한 기존노드저장
vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s(0), e(0), t(0);
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
    }
    cin >> st >> ed;

    for(int i = 0; i <= n; i++)
    {
        values[i] = INF;
        routes[i] = -1;
    }
    values[st] = 0;
    pq.push({0, st});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (values[cur] < dist) continue; // 이미 처리해준경로보다 더 긴 경로인 경우 무시

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int nextCur = graph[cur][i].first;
            int nextDist = graph[cur][i].second;

            if(nextDist + dist < values[nextCur])
            {
                values[nextCur] = nextDist + dist;
                routes[nextCur] = cur;
                pq.push({values[nextCur], nextCur});
            }
        }
    }

    cout << values[ed] << '\n';

    ans.push_back(ed);

    while(ans.back() != st) // 경로 역추적
    {
        int cur = ans.back();
        ans.push_back(routes[cur]);
    }

    cout << ans.size() << '\n';

    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";

    return 0;
}