#include <iostream>

using namespace std;

/*수학적 규칙을 찾아 dp 점화식을 세운다.
1  2  3  4  5  6  7
1  2  4  7  13 24 44   
d[n] = d[n - 3] + d[n - 2] +d[n - 1];*/

int T(0), n(0);
int dp[11] = {0,};

int main(void)
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] +dp[i - 1];
    }

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}