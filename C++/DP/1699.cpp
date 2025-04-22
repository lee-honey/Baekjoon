#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N(0);
int DP[100001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[1] = 1;

    for(int i = 2; i <= N; i++)
    {
        int sqrtNum = sqrt(i);
        if(sqrtNum * sqrtNum == i)
        {
            DP[i] = 1;
        }
        else
        {
            DP[i] = DP[i - 1] + 1;
            for(int j = 1; j <= sqrtNum; j++)
                DP[i] = min(DP[i], DP[j * j] + DP[i - j * j]);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}