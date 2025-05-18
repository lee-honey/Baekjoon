#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V(0);
int S(0), E(0), D(0);
vector<bool> vecVisited;
vector<pair<int, int>> node[100001];
int maxDist(-1), maxNode(0);

void DFS(int now, int dist)
{
    vecVisited[now] = true; // 방문한곳은방문했다고 바꿔주고고
    if(maxDist < dist) // 길이가 길어지면 갱신
    {
        maxDist = dist; // 최종 가장 먼 정점에서 먼 정점까지의 길이가 답임
        maxNode = now; // 가장 먼 정점을 갱신
    }

    for(int i = 0; i < node[now].size(); i++) // 시작점 노드 순환하면서서
    {
        if(vecVisited[node[now][i].first])
            continue;
        DFS(node[now][i].first, dist + node[now][i].second); // 방문한적이 없는 경우 길이 갱신하면서 깊이탐색
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;
    vecVisited.resize(V + 1);
    for(int i = 0; i < V; i++)
    {
        cin >> S;
        while(1)
        {
            cin >> E;
            if(E == -1)
                break;
            cin >> D;
            node[S].push_back({E, D}); // 이런식으로 양방향트리정보구성
            node[E].push_back({S, D});
        }
    }
    DFS(1, 0); // 임의의 정점으로부터 가장 먼 정점 구함함
    vecVisited.assign(V + 1, false);
    maxDist = -1;
    DFS(maxNode, 0); // 가장 먼 정점으로부터 가장 먼 정점
    cout << maxDist << '\n';

    return 0;
}