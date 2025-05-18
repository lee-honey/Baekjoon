// 벨만포드인데 플로이드와샬로품

#include <iostream>
#define INF 10000000
using namespace std;

int TC(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    while(TC--)
    {
        int N(0), M(0), W(0);
        cin >> N >> M >> W;

        int road[501][501];

        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= N; j++)
            {
                road[i][j] = INF;
                if(i == j)
                    road[i][j] = 0;
            }
        }

        for(int i= 0; i < M; i++)
        {
            int S(0), E(0), T(0);
            cin >> S >> E >> T;
            if(T < road[S][E])
                road[S][E] = T;
            if(T < road[E][S])
                road[E][S] = T;
        }

        for(int i = 0; i < W; i++)
        {
            int S(0), E(0), T(0);
            cin >> S >> E >> T;
            if(-T < road[S][E])
                road[S][E] = -T;
        }

        for(int k = 1; k <= N; k++)
        {
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    if(road[i][k] + road[k][j] < road[i][j])
                        road[i][j] = road[i][k] + road[k][j];
                }
            }
        }

        bool bIsMinus = false;

        for(int i = 1; i <= N; i++)
        {
            if(road[i][i] < 0)
            {
                bIsMinus = true;
                break;
            }
        }

        if(bIsMinus == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }



    return 0;
}