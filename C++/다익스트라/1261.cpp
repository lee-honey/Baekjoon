#include <iostream>
#include <queue>
#define INF 2147483647

using namespace std;

int M(0), N(0);
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>
        , greater<pair<int, pair<int,int>>>> pq;
int arr[101][101] = {0,};
int values[101][101] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++)
            arr[i][j] = str[j] - '0';
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            values[i][j] = INF;
    
    pq.push({0, {0, 0}});
    values[0][0] = 0;
    while(!pq.empty())
    {
        int depth = pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();
        if(values[curX][curY] < depth)
            continue;
        for(int i = 0; i < 4; i++)
        {
            int nextDepth = depth;
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
            {
                if(arr[nextX][nextY] == 1)
                    nextDepth += 1;
                if(nextDepth < values[nextX][nextY])
                {
                    values[nextX][nextY] = nextDepth;
                    pq.push({nextDepth,{nextX,nextY}});
                }
            }
        }
    }
    cout << values[N - 1][M - 1] << '\n';

    return 0;
}