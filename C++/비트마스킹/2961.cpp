#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N(0);
int sinn[11] = {0,};
int ssen[11] = {0,};
int ans(2147483647);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> sinn[i] >> ssen[i];
    }

    for(int i = 1; i < (1 << N); i++) // 1부터 2^N-1까지
    {
        int gop(1), hap(0);
        for(int j = 0; j < N; j++)
        {
            if(i & (1 << j)) // ex) i = 5 (101) / j = 001, 010, 100
            {
                gop *= sinn[j];
                hap += ssen[j];
            }
        }
        ans = min(ans, abs(gop - hap));
    }

    cout << ans << '\n';

    return 0;
}