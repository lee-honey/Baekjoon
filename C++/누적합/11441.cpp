#include <iostream>
#include <vector>

using namespace  std;

int N(0), M(0);
int arr[100001] = {0,};
int prefix[100001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= N; i++)
        prefix[i] = arr[i] + prefix[i - 1];

    cin >> M;
    while(M--)
    {
        int i(0), j(0);
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << '\n';
    }

    return 0;
}