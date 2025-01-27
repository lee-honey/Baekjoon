#include <iostream>
#include <queue>

using namespace std;

int A(0), B(0);
queue<pair<long long, int>> que;
int ans(-1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    que.push({A, 1});

    while (!que.empty())
    {
        pair<long long, int> cur = que.front();
        que.pop();

        if (cur.first == B)
        {
            ans = cur.second;
            break;
        }

        if (2 * cur.first <= B)
            que.push({2 * cur.first, cur.second + 1});
        if (10 * cur.first + 1 <= B && 10 * cur.first + 1 > 0)
            que.push({10 * cur.first + 1, cur.second + 1});
    }

    cout << ans << '\n';

    return 0;
}
