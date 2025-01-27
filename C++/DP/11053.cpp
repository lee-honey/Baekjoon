#include <iostream>

using namespace std;

int N(0), ans(0);
int A[1001] = {0,};
int DP[1001] = {0,};

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i] > A[j] && DP[i] <= DP[j])
                DP[i] = DP[j] + 1;
            if(ans < DP[i])
                ans = DP[i];
        }
    }

    cout << ans << '\n';

    return 0;
}