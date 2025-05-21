//BFS는 무조건 visited 체크를 해줘야된다고 하오.

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T(0), I(0);
int arr[301][301] = {0,};
bool bIsVisited[301][301] = {false, };
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
pair<int, int> st;
pair<int, int> ed;
int ans(2147483647);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(bIsVisited, false, sizeof(bIsVisited));
        queue<pair<int, pair<int, int>>> que;
        ans = 2147483647;
        cin >> I;
        cin >> st.first >> st.second;
        cin >> ed.first >> ed.second;
        que.push({0, {st.first, st.second}});
        while(!que.empty())
        {
            int depth = que.front().first;
            int curX = que.front().second.first;
            int curY = que.front().second.second;
            que.pop();
            if(curX == ed.first && curY == ed.second)
            {
                ans = min(depth, ans);
                break;
            }
            for(int i = 0; i < 8; i++)
            {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if(0 <= nextX && nextX < I && 0 <= nextY && nextY < I && bIsVisited[nextX][nextY] == false)
                {
                    bIsVisited[nextX][nextY] = true;
                    que.push({depth + 1, {nextX , nextY}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}