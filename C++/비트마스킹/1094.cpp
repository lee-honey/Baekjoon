#include <iostream>

using namespace std;

int X(0);
int cnt(1);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X;

    int stick(64);
    int smallStick(stick);

    while(1)
    {
        if(stick == X)
            break;
        
        smallStick = smallStick >> 1;
        if(stick - smallStick >= X)
            stick -= smallStick;
        else
            ++cnt;
    }

    cout << cnt << '\n';

    return 0;
}