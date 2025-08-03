#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N(0);
vector<int> vec;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vec.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    for(int i = N - 1; i >= 1; i--)
    {
        while(vec[i - 1] >= vec[i])
        {
            vec[i - 1] -= 1;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}