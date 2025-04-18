#include <iostream>

using namespace std;

int N(0);
int MOD(9901);
int DP[100001][2] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[1][0] = 2;
    DP[1][1] = 1;

    for(int i = 2; i <= N; i++)
    {
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] * 2) % MOD;
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
    }

    cout << (DP[N][0] + DP[N][1]) % MOD << '\n';

    return 0;
}