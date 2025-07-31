#include <iostream>

using namespace std;

int T(0), C(0);
int Q(0), D(0), N(0), P(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        cin >> C;
        Q = C / 25;
        C -= Q * 25;

        D = C / 10;
        C -= D * 10;

        N = C / 5;
        C -= N * 5;

        cout << Q << " " << D << " " << N << " " << C << "\n";
    }

    return 0;
}