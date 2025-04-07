#include <iostream>
int MIN(int a, int b){return (a < b) ? a : b;}
using namespace std;

int x(0), y(0), w(0), h(0);
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> w >> h;
    int minX = MIN(w - x, x);
    int minY = MIN(h - y, y);

    ans = MIN(minX, minY);

    cout << ans << '\n';

    return 0;
}