// 다익스트라. INF값때메 헤멘 레전드문제
// que는 거리, 노드 순으로 넣어줘야함

#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647 // value의 최대값도 이를 넘을 순 없다는 가정하에 INF는 이만큼 최대값으로 설정해줘야됨.
// 1000 * 100000 = 100000000

using namespace std;

int n(0), m(0), st(0), ed(0);
vector<pair<int, int>> graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
int values[1001];
int routes[1001] = {0, };

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

    que.push({0, st});

    while(!que.empty())
    {
        int dist = que.top().first;
        int cur = que.top().second;
        que.pop();

        if(values[cur] < dist)
            continue;

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int nextNode = graph[cur][i].first;
            int nextDist = graph[cur][i].second;

            if(dist + nextDist < values[nextNode])
            {
                routes[nextNode] = cur;
                values[nextNode] = dist + nextDist;
                que.push({values[nextNode], nextNode});
            }
        }
    }

    cout << values[ed] << '\n';

    vector<int> ans;
    
    ans.push_back(ed);

    while(ans.back() != st)
    {
        int cur = ans.back();
        if (routes[cur] == -1) break;
        ans.push_back(routes[cur]);
    }

    cout << ans.size() << '\n';

    for(int i = ans.size() - 1; 0 <= i; i--)
        cout << ans[i] << " ";

    return 0;
}