#include <iostream>
#include <cmath>

using namespace std;

int n = 0;
int dp[50001] = {0, };

int Min(int a, int b){ return (a < b) ? a : b; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= sqrt(n); i++)
        dp[i * i] = 1;

    for(int i = 1; i <=n; i++)
    {
        int iMin = 2147483647;
        if(dp[i] != 1)
        {
            for(int j = 1; j <= sqrt(i); j++)
            {
                iMin = Min(iMin, dp[j * j] + dp[i - j * j]);
            }
            dp[i] = iMin;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}