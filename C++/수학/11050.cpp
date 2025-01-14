#include <iostream>

using namespace std;

int N = 0, K = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int gop1 = 1, gop2 = 1;
    for(int i = N; i > N - K; i--)
    {
        gop1 *= i;
    }

    for(int i = K; i > 0; i--)
    {
        gop2 *= i;
    }

    cout << gop1 / gop2 << endl;

    return 0;
}