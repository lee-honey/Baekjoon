// 플로이드 와샬

#include <iostream>

using namespace std;

const int INF(10000000); // 오버플로우 방지

int n(0), m(0);
int dis[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            dis[i][j] = INF;
            if(i == j)
                dis[i][j] = 0;
        }

    for(int i = 0; i < m; i++)
    {
        int a(0), b(0), c(0);
        cin >> a >> b >> c;
        if(c < dis[a][b])
            dis[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dis[i][j] == INF)
                cout << "0 ";
            else
                cout << dis[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}