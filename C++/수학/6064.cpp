#include <iostream>

using namespace std;

int T(0), M(0), N(0), x(0), y(0), k(0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        k = -1;
        cin >> M >> N >> x >> y;

        for(int b = 0; b < M; b++)
        {
            if((N * b + y - x) % M == 0)
            {
                k = N * b + y;
                break;
            }
        }

        cout << k << '\n';
    }

    return 0;
}