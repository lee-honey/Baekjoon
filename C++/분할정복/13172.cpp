#include <iostream>
#define MOD 1000000007

using namespace std;

int M(0);
long long ans(0);

long long Modular(long long x, long long y)
{
    if(y == 1)
        return x;
    if(y % 2 == 0)
    {
        long long value = Modular(x, y / 2);
        return (value * value) % MOD;
    }
    else
    {
        return (x * Modular(x, y - 1)) % MOD;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    while(M--)
    {
        long long N(0), S(0);
        cin >> N >> S;

        long long val(0);
        val = S * Modular(N, MOD - 2);

        ans += val % MOD;
    }

    cout << ans % MOD <<'\n';

    return 0;
}