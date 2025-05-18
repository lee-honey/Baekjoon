#include <iostream>
#include <algorithm>

using namespace std;

int N(0), M(0);
int arr[1001][1001] = {0,};
int DP[1001][1001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            DP[i][j] = max(DP[i][j - 1] + arr[i][j] , DP[i - 1][j] + arr[i][j]);
        }
    }

    cout << DP[N][M] << '\n';

    return 0;
}