// 다익스트라
// 1. 우선순위 큐가 있어야 함. (pq의 pair의 first는 갱신된 경로값, second에는 현재 위치가 있을 것. 가장 가까운 경로부터 찾기 위함임)
// 매 상황에서 가장 비용이 적은 노드를 선택해 임의의 과정을 반복 -> 일종의 그리디
// 2. pair<int, int>를 품는 인접리스트 벡터가 있어야 함
// 3. 경로 상태를 저장하는 values배열이 있어야할것
// 4. dist가 values보다 큰 경우는 최단경로가 갱신될 수 없으므로 건너뜀
// 5. 현재 노드에서 갈 수 있는 모든 경로에 대해 현재까지 갱신해 온 최단거리 + 다음 거리가 values보다 작으면 values를 갱신하면서 pq에 push
// 6. 우선순위 큐가 빌 때까지 반복해서 values[목적지]를 구한다.

#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647

using namespace std;

int V(0), E(0), K(0);
int values[20001] = {0,};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graphs[20001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++)
    {
        int u(0), v(0), w(0);
        cin >> u >> v >> w;
        graphs[u].push_back({v, w});
    }
    for(int i = 1; i <= V; i++)
        values[i] = INF;
    
    values[K] = 0;
    pq.push({0, K});
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(values[cur] < dist)
            continue;

        for(int i = 0; i < graphs[cur].size(); i++)
        {
            int nextDist = graphs[cur][i].second;
            int nextNode = graphs[cur][i].first;
            if(dist + nextDist < values[nextNode])
            {
                values[nextNode] = dist + nextDist;
                pq.push({values[nextNode], nextNode});
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        if(values[i] == INF)
            cout << "INF" << '\n';
        else
            cout << values[i] << '\n';
    }

    return 0;
}