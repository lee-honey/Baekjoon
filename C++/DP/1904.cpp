#include <iostream>

using namespace std;

const int MOD(15746);
int N(0);
int DP[1000001][2];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[1][0] = 0;
    DP[1][1] = 1;
    DP[2][0] = 1;
    DP[2][1] = 1;

    for(int i = 3; i <= N; i++)
    {
        DP[i][0] = (DP[i - 2][0] + DP[i - 2][1]) % MOD;
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
    }

    cout << (DP[N][0] + DP[N][1]) % MOD << '\n';

    return 0;
}