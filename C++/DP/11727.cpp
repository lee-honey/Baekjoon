#include <iostream>

using namespace std;

int dp[1001] = {0, 1, 3, };
int n = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 3; i <= 1000; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cin >> n;

    cout << dp[n] << '\n';

    return 0;
}