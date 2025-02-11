#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int N, M, s, e, d, V1, V2;
int node[801][801];
int value[801];

int dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 1; i <= N; i++)
        value[i] = INF;

    value[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int st = pq.top().second;
        pq.pop();

        if (value[st] < dist) continue;

        for (int i = 1; i <= N; i++) {
            if (node[st][i] == INF) continue;

            int newDist = dist + node[st][i];
            if (newDist < value[i]) {
                value[i] = newDist;
                pq.push({newDist, i});
            }
        }
    }
    return value[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            node[i][j] = INF;

    for (int i = 1; i <= N; i++)
        node[i][i] = 0;

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> d;
        node[s][e] = node[e][s] = min(node[s][e], d);
    }

    cin >> V1 >> V2;

    int path1 = 0, path2 = 0;

    // 첫 번째 경로: 1 -> V1 -> V2 -> N
    int p1_1 = dijkstra(1, V1);
    int p1_2 = dijkstra(V1, V2);
    int p1_3 = dijkstra(V2, N);

    if (p1_1 == INF || p1_2 == INF || p1_3 == INF)
        path1 = INF;
    else
        path1 = p1_1 + p1_2 + p1_3;

    // 두 번째 경로: 1 -> V2 -> V1 -> N
    int p2_1 = dijkstra(1, V2);
    int p2_2 = dijkstra(V2, V1);
    int p2_3 = dijkstra(V1, N);

    if (p2_1 == INF || p2_2 == INF || p2_3 == INF)
        path2 = INF;
    else
        path2 = p2_1 + p2_2 + p2_3;

    int result = min(path1, path2);
    if (result == INF)
        cout << "-1\n";
    else
        cout << result << '\n';

    return 0;
}
