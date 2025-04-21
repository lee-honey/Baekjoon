#include <iostream>

using namespace std;

int n(0), k(0);
int arr[101] = {0,};
int DP[10301] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    DP[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = arr[i]; j <= k; j++)
        {
            DP[j] = DP[j] + DP[j - arr[i]];

            // 계산식을 구해가면서 누적한 값을 이용하는 기법
        }
    }

    cout << DP[k] << '\n';

    return 0;
}