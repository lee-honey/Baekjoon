#include <iostream>

using namespace std;

int a(0), b(0), c(0), d(0), e(0), f(0);
int x(0), y(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d >> e >> f;

    if(a != 0)
    {
        int tempA = a;
        a *= d;         b *= d;         c *= d;
        d *= tempA;     e *= tempA;     f *= tempA;

        y = (c - f) / (b - e);
        x = (c - b * y) / a;
    }
    else
    {
        y = (c - a) / b;
        x = (f - e * y) / d;
    }

    cout << x << " " << y << '\n';

    return 0;
}