#include <iostream>

using namespace std;

int N(0), A(0), B(0);
int ans(0), mod(1);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B;
    A--;
    B--;

    while(mod < N)
    {
        mod *=2;
        ++ans;
        if(A / mod == B / mod)
            break;
    }

    cout << ans << '\n';

    return 0;
}