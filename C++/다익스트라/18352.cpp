#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647

using namespace std;

int N(0), M(0), K(0), X(0);
vector<pair<int, int>> graph[300001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int values[300001] = {0,};
vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++)
    {
        int s(0), e(0);
        cin >> s >> e;
        graph[s].push_back({e, 1});
    }
    for(int i = 0; i <= N; i++)
        values[i] = INF;
    values[X] = 0;
    pq.push({0, X});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(values[cur] < dist)
            continue;

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int nextNode = graph[cur][i].first;
            int nextDist = graph[cur][i].second;
            if(dist + nextDist < values[nextNode])
            {
                values[nextNode] = dist + nextDist;
                pq.push({values[nextNode], nextNode});
            }
        }
    }

    for(int i = 0; i <=N; i++)
        if(values[i] == K)
            ans.push_back(i);

    if(ans.size() == 0)
        cout << "-1" << '\n';
    else
    {
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << '\n';
    }

    return 0;
}