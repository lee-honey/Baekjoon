#include <iostream>

using namespace std;

int arr[5] = {0,};
int result = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 5; i++)
        cin >> arr[i];

    for(int i = 0; i < 5; i++)
        result += arr[i] * arr[i];

    cout << result % 10 << '\n';

    return 0;

}