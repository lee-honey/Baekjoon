#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int         F(0), S(0), G(0), U(0), D(0);
queue<pair<int, int>>  que;
bool        bIsVisited[1000001] = {false,};
int         ans(2147483647);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    que.push({0, S});
    bIsVisited[S] = true;

    while(!que.empty())
    {
        int cur = que.front().second;
        int depth = que.front().first;
        que.pop();

        if(cur == G)
        {
            ans = min(ans, depth);
            break;
        }

        int up = cur + U;
        int down = cur - D;

        if(up <= F && bIsVisited[up] == false)
        {
            bIsVisited[up] = true;
            que.push({depth + 1, up});
        }
        if(down >= 1 && bIsVisited[down] == false)
        {
            bIsVisited[down] = true;
            que.push({depth + 1, down});
        }
    }

    if(ans == 2147483647)
        cout << "use the stairs" << '\n';
    else
        cout << ans << '\n';

    return 0;
}