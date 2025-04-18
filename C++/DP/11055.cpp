#include <iostream>
#include <algorithm>

using namespace std;

int N(0);
int A[1001] = {0,};
int DP[1001] = {0,};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < N; i++)
    {
        DP[i] = A[i];

        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i] && DP[j] + A[i] > DP[i])
            {
                DP[i] = DP[j] + A[i];
            }
        }
    }

    for(int i = 0; i < N; i++)
        ans = max(DP[i], ans);

    cout << ans << '\n';

    return 0;
}