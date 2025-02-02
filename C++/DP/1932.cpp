//뒤에서부터 계산하는 스킬 기르기.

#include <iostream>

using namespace std;

int n(0);
int arr[501][501] = {0,};
int DP[501] = {0,};
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    DP[0] = arr[0][0];
    ans = DP[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(j == 0)
                DP[j] = DP[j] + arr[i][j];
            else if(j == i)
                DP[j] = DP[j - 1] + arr[i][j];
            else
                DP[j] = ((DP[j - 1] > DP[j]) ? DP[j - 1] : DP[j]) + arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        ans = (ans > DP[i]) ? ans : DP[i];

    cout << ans << '\n';

    return 0;
}