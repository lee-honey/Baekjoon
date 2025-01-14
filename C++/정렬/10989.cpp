#include <iostream>

using namespace std;

int N = 0;
int arr[10001] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--)
    {
        int a = 0;
        cin >> a;
        arr[a]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 0; j < arr[i]; j++)
            cout << i << '\n';
    }

    return 0;
}