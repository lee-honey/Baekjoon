#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), M(0);
vector<int> vec;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vec.resize(N);

    for(int i = 0; i < N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(vec[i] + vec[j] > M)
                break;

            if(vec[i] + vec[j] == M)
                ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}