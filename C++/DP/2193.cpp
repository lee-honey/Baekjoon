#include <iostream>

using namespace std;

int N(0);
long long DP[91][2] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[1][0] = 0;
    DP[1][1] = 1;

    for(int i = 2; i <= N; i++)
    {
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
        DP[i][1] = DP[i - 1][0];
    }

    cout << DP[N][0] + DP[N][1] << '\n';

    return 0;
}