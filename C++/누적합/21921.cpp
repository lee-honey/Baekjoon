#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N(0), X(0);
int arr[250001] = {0,};
int prefix[250001] = {0,};
int ans(0);
unordered_map<int, int> mp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;

    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        prefix[i] = arr[i] + prefix[i - 1];
    }

    for(int i = X; i <= N; i++)
    {
        if(ans <= prefix[i] - prefix[i - X])
        {
            ans = prefix[i] - prefix[i - X];
            mp[ans]++;
        }
    }

    if(ans == 0)
        cout << "SAD" << '\n';
    else
    {
        cout << ans << '\n';
        cout << mp[ans] << '\n';
    }

    return 0;
}