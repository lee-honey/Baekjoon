#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0);
vector<int> vec;

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

    sort(vec.begin(), vec.end());

    for(int i = N - 1; i >= 0; i--)
        cout << vec[i] << "\n";

    return 0;
}