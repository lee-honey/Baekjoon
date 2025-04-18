#include <iostream>

using namespace std;

int N(0);
int MOD(10007);
long long DP[1001][11] = {0,};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i <= 9; i++)
        DP[0][i] = 1;

    for(int i = 0; i <= N; i++)
        DP[i][0] = 1;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    cout << DP[N][9] << '\n';

    return 0;
}