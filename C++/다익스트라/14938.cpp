#include <iostream>
#define INF 10000

using namespace std;

int n(0), m(0), r(0);
int item[101];
int dis[101][101];
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++)
        cin >> item[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if(i == j)
                dis[i][j] = 0;
        }
    }

    for(int i = 0; i < r; i++)
    {
        int a(0), b(0), l(0);
        cin >> a >> b >> l;
        if(l < dis[a][b])
            dis[a][b] = l;
        if(l < dis[b][a])
            dis[b][a] = l;
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
        int temp(0);
        for(int j = 1; j <= n; j++)
        {
            if(dis[i][j] <= m)
                temp += item[j];
        }
        if(ans < temp)
            ans = temp;
    }

    cout << ans << '\n';

    return 0;
}