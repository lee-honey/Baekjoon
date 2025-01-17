#include <iostream>

using namespace std;

long long dp[101] = {0, 1, 1, 1, 2, };
int T = 0, N = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int i = 5; i <= 101; i++)
        dp[i] = dp[i - 5] + dp[i -1];

    while(T--)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}