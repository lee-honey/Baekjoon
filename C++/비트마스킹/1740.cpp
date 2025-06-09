#include <iostream>
#include <cmath>

using namespace std;

long long N(0);
long long ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    long long base = 1;
    for(int i = 0; i < 60; i++)
    {
        if(N & (1LL << i))
            ans += base;
        base *= 3;
    }

    cout << ans << '\n';

    return 0;
}