// // 다익스트라 알고리즘을 이용해 최소비용을 구해야하는 문제.
// // 다익스트라 - DP를 이용하여 최소거리를 구하는 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int node[1001][1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int value[1001];    // 출발지에서 각 노드에 도달했을 때의 최단거리
int N(0), M(0);
int s(0), e(0), d(0);
int Start(0), End(0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            node[i][j] = INF;       // 초기 노드는 INF로 초기화해준다.
        }
    }

    for(int i = 1; i <= N; i++)
    {
        node[i][i] = 0;
        value[i] = INF;
    }

    for(int i = 0; i < M; i++)
    {
        cin >> s >> e >> d;
        if(d < node[s][e])
            node[s][e] = d;
    }

    cin >> Start >> End;
    value[Start] = 0;

    pq.push({0, Start});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(value[now] < dist) continue;

        for(int i = 1; i <= N; i++)
        {
            int curNode = i;
            int curDist = node[now][i];

            if(curDist == INF || now == curNode)continue;

            if(dist + curDist < value[curNode])
            {
                value[curNode] = dist + curDist;
                pq.push({dist + curDist, curNode});
            }
        }
    }

    cout << value[End] << '\n';

    return 0;
}

