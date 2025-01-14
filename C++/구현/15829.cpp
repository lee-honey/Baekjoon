#include <iostream>

using namespace std;

int L = 0;
int arr[50] = {0,};
long long result = 0, R = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L;

    for(int i = 0; i < L; i++)
    {
        char c;
        cin >> c;
        arr[i] = (int)(c) - (int)('a') + 1;
    }

    for(int i = 0; i < L; i++)
    {
        result = (result + arr[i] * R) % 1234567891;
        R = (R * 31) % 1234567891;
    }

    cout << result << '\n';

    return 0;
}