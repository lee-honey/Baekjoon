#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647

using namespace std;

int N(0), M(0);
vector<pair<int, int>> vec[50001];
int values[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    while(M--)
    {
        int s(0), e(0), d(0);
        cin >> s >> e >> d;
        vec[s].push_back({e, d});
        vec[e].push_back({s, d});
    }
    for(int i = 0; i <= N; i++)
        values[i] = INF;

    pq.push({0, 1});
    values[1] = 0;

    while(!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(values[curNode] < curDist)
            continue;
        
        for(int i = 0; i < vec[curNode].size(); i++)
        {
            int nextDist = vec[curNode][i].second + curDist;
            int nextNode = vec[curNode][i].first;
            if(nextDist < values[nextNode])
            {
                values[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    cout << values[N] << '\n';

    return 0;
}