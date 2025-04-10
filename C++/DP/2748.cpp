#include <iostream>

using namespace std;

int n(0);

long long DP[100] = {0,};
long long ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    DP[0] = 0;
    DP[1] = 1;

    for(int i = 2; i <= n; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    cout << DP[n] << '\n';

    return 0;
}