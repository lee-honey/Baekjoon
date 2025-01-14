#include <iostream>

using namespace std;

int N = 0, M = 0, i = 0, j = 0, a = 0, b = 0;
int arr[100001] = {0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int k = 0; k < N; k++)
    {
        cin >> arr[k];
        if(k >= 1)
            arr[k] += arr[k - 1];
    }

    for(int m = 0; m < M; m++)
    {
        cin >> i >> j;
        
        a = arr[j - 1];
        b = (i - 2 < 0) ? 0 : arr[i - 2];

        cout << a - b  << '\n';
    }

    return 0;
}