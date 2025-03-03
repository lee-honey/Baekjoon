#include <iostream>

using namespace std;

int n(0);
int arr[10001];
int DP[10001];
int ans(0);

int Max(int a, int b){return (a > b) ? a : b;}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++)
    {
        if(i== 1)
            DP[i] = arr[i];
        else if(i == 2)
            DP[i] = arr[i] + arr[i - 1];
        else if(i == 3)
            DP[3] = Max(DP[i - 1], Max(arr[i] + arr[i - 1], arr[i] + arr[i - 2])); // 3가지 경우중 하나가 DP
        else
            DP[i] = Max(DP[i - 1], Max(arr[i] + DP[i - 2], arr[i] + arr[i - 1] + DP[i - 3])); // 3가지 경우중 하나가 Dp
        if(ans < DP[i])
            ans = DP[i];
    }

    cout << ans << '\n';

    return 0;
}