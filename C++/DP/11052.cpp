#include <iostream>
#include <algorithm>

using namespace std;

int N(0);
int P[1001] = {0,};
int DP[1001] = {0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> P[i];

    DP[1] = P[1];

    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
            DP[i] = max(DP[i], DP[i - j] + P[j]);
    }

    cout << DP[N] << '\n';

    return 0;
}