#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), K(0), ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vector<int> arr;
    vector<int> vec;

    for(int i = 0; i < N; i++)
    {
        int temp(0);
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i < N; i++)
    {
        int temp(0);
        temp = arr[i] - arr[i - 1];
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < N - K; i++)
        ans += vec[i];

    cout << ans << '\n';
    
    return 0;
}