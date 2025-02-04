#include <iostream>

using namespace std;

int N(0), M(0);
int arr[1025][1025];
int DP[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            DP[i][j] = arr[i][j] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
        }

    for(int i = 0; i < M; i++)
    {
        int x1(0), y1(0), x2(0), y2(0);
        
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = DP[x2][y2] - DP[x2][y1-1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }

    return 0;
}