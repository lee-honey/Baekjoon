#include <iostream>

using namespace std;

int N(0), K(0);
int MOD(10007);
int DP[1001][1001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N; i++)
    {
        DP[i][1] = i;
        DP[i][0] = 1;
    }

    for(int i = 2; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            DP[j][i] = (DP[j - 1][i - 1] + DP[j - 1][i]) % MOD;
        }
    }

    cout << DP[N][K] << '\n';

    return 0;
}