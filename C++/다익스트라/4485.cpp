#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647

using namespace std;

int N(0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int values[126][126] = {0,};
int graphs[126][126] = {0,};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
greater<pair<int, pair<int, int>>>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx = 0;
    while(1)
    {
        cin >> N;
        if(N == 0)
            break;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> graphs[i][j];
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                values[i][j] = INF;
            }
        }
        values[0][0] = graphs[0][0];
        pq.push({values[0][0],{0, 0}});
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;
            pq.pop();
            if(values[curX][curY] < dist)
                continue;
            for(int i = 0; i < 4; i++)
            {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if(0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
                {
                    int nextDist = dist + graphs[nextX][nextY];
                    if(nextDist < values[nextX][nextY])
                    {
                        values[nextX][nextY] = nextDist;
                        pq.push({nextDist, {nextX, nextY}});
                    }
                }
            }

        }
        cout << "Problem " << ++idx << ": ";
        cout << values[N - 1][N - 1] << '\n';
    }

    return 0;
}