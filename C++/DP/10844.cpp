#include <iostream>
#define MOD 1000000000

using namespace std;

int N(0);
long long DP[101][11]; // [11]: 가장 마지막에 나오는 수
long long ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[1][0] = 0;
    for(int i = 1; i <= 9; i++)
        DP[1][i] = 1;

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
                DP[i][j] = DP[i - 1][j + 1] % MOD;
            else if(j == 9)
                DP[i][j] = DP[i - 1][j - 1] % MOD;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;            
        }
    }

    for(int i = 0; i <= 9; i++)
        ans += DP[N][i];
    
    cout << ans % MOD << '\n';

    return 0;
}