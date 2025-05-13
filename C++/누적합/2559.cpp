#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), K(0), ans(0), curHap(0);

int main(void)
{
    cin >> N >> K;
    vector<int> vec(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
        if(i < K)
            curHap += vec[i];
    }
    ans = curHap;
    for(int i = K; i < N; i++)
    {
        curHap -= vec[i - K];
        curHap += vec[i];
        ans = max(curHap, ans);
    }

    cout << ans << '\n';

    return 0;
}