// 다익스트라: 우선순위 큐 필수
// 우선순위 큐의 목적: 출발점부터 시작하여 큐가 빌 때까지 해당하는 위치까지의 거리를 첫번째 요소에 저장하여
// 거리가 짧은 순으로 while문이 돌아가도록 함
// 앞에있는 것부터 뽑되, 최종 세팅된 최단거리(values[now])보다 dist가 클 경우 values를 갱신해줘야함
// graph[now]에서 연결된 지점에 대해 순회하며 nextNode, nextCost를 지정해줌
// 이 때, nextCost = dist + 그래프에 나와있는 거리
// values가 nextCost보다 크면 values를 갱신하고, 우선순위 큐에 새로운 위치의 것을 넣어줌
// values[D]가 최종적인 결과물이 됨

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