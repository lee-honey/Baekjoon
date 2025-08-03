#include <iostream>

using namespace std;

int T(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    int A = T / 300;
    T -= 300 * A;
    int B = T / 60;
    T -= 60 * B;
    int C = T / 10;
    T -= 10 * C;

    if(T == 0)
        cout << A << " " << B << " " << C << '\n';
    else
        cout << "-1" << '\n';

    return 0;
}