#include <iostream>
#include <string>

using namespace std;

int N(0), F(0);
int temp(0);
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> F;

    N -= N % 100;

    for(int i = 0; i < 100; i++)
    {
        temp = N + i;
        if(temp % F == 0)
            break;
    }

    ans = temp - N;
    if(ans < 10)
        cout << '0';
    cout << ans << '\n';

    return 0;
}