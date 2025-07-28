#include <iostream>
#include <algorithm>

using namespace std;

int T(0);
int arr[10];
int N(3);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--)
    {
        for(int i = 0; i < 10; i++)
            cin >> arr[i];

        sort(arr, arr + 10);
        cout << arr[7] << '\n';
    }

    return 0;
}