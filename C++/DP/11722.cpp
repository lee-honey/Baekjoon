#include <iostream>
#include <algorithm>

using namespace std;

int N(0);
int A[1001] = {0,};
int DP[1001] = {0,};

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
        DP[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(A[j] > A[i] && DP[j] + 1 > DP[i])
                DP[i] = DP[j] + 1;
        }
    }

    int iMax(0);

    for(int i = 0; i < N; i++)
        iMax = max(iMax, DP[i]);

    cout << iMax << '\n';

    return 0;
}