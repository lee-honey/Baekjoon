#include <iostream>

using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;
    cout << A + B - C << '\n';

    int tempB = B;
    int dev = 0;
    while (B > 0)
    {
        B /= 10;
        dev++;
    }

    for(int i = 0; i < dev; i++)
        A *= 10;

    cout << (A + tempB) - C << '\n';

    return 0;
}