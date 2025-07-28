#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0);
int k(0);
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> k;

    vec.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    cout << vec[N - k] << '\n';

    return 0;
}