#include <iostream>

using namespace std;

int MAX(int a, int b){return (a > b) ? a : b;}

int n(0);
int arr[100001] = {0, };
int DP[100001] = {0,};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ans = arr[0];
    DP[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        DP[i] = MAX(DP[i - 1] + arr[i], arr[i]);
        ans = MAX(ans, DP[i]);
    }

    cout << ans << '\n';

    return 0;
}