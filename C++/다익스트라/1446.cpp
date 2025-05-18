#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2147483647

using namespace std;

int N(0), D(0);
int values[10001];
vector<pair<int, int>> graph[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;
    for(int i = 0; i <= D; i++)
        values[i] = INF;
    for(int i = 0; i < N; i++)
    {
        int st(0), ed(0), dis(0);
        cin >> st >> ed >> dis;
        graph[st].push_back({ed, dis});
    }
    for(int i = 0; i < D; i++)
        graph[i].push_back({i + 1, 1}); // 각 정수 정점으로부터 다음 정점으로까지 거리 1만큼 모두가 가지고있음

    pq.push({0, 0});
    values[0] = 0;
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(values[now] < dist)  continue; // 최솟값 values가 갱신될 조건이면 아래를 진행하고 아닐경우 건너뜀.
        for(int i = 0; i < graph[now].size(); i++)
        {
            int nextNode = graph[now][i].first;
            int nextCost = dist + graph[now][i].second;
            if(nextCost < values[nextNode])
            {
                values[nextNode] = nextCost;
                pq.push({values[nextNode], nextNode});
            }
        }
    }

    cout << values[D] << '\n';

    return 0;
}