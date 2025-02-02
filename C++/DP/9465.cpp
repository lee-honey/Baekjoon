#include <iostream>

using namespace std;

int T(0), ans(0);

int max(int a, int b){return a > b ? a : b;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        int arr[2][100003] = {0,};
        int DP[2][100003] = {0,};
        int n(0);
        
        cin >> n;
        
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= n; j++)
                cin >> arr[i][j];

        DP[0][0] = 0;           DP[1][0] = 0;
        DP[0][1] = arr[0][1];   DP[1][1] = arr[1][1];

        for(int i = 2; i <= n; i++)
        {
            DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + arr[0][i];
            DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + arr[1][i];
        }

        cout << max(DP[0][n], DP[1][n]) <<'\n';
    }

    return 0;
}