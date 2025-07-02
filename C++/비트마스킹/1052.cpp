#include <iostream>

using namespace std;

int N(0), K(0);
int ans(0);

int CountOne(int n)
{
    int num(0);
    while(n > 0)
    {
        if((n & 1) == 1)
            num++;
        n >>= 1;
    }
    return num;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    while(1)
    {
        if(CountOne(N) <= K)
            break;
        ans++;
        N++;
    }

    cout << ans << '\n';

    return 0;
}