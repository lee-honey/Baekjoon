#include <iostream>
#include <queue>

using namespace std;

int N(0), K(0), ans(0);
bool visited[100001];
queue<pair<int, int>> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    que.push({N, 0});

    while(!que.empty())
    {
        int curPos = que.front().first;
        int curTime = que.front().second;
        que.pop();

        visited[curPos] = true;

        if(curPos == K)
        {
            ans = curTime;
            break;
        }

        if(curPos * 2 <= 100000 && !visited[curPos * 2])
            que.push({curPos * 2, curTime});
        if(curPos - 1 >= 0 && !visited[curPos - 1])
            que.push({curPos - 1, curTime + 1});
        if(curPos + 1 <= 100000 && !visited[curPos + 1])
            que.push({curPos + 1, curTime + 1});
    }

    cout << ans << '\n';

    return 0;
}