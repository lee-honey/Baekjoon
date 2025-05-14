#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N(0), M(0), ans(0);
int six[101] = {0,};
int one[101] = {0,};
int minSix(INT_MAX), minOne(INT_MAX);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> six[i] >> one[i];
        minSix = min(six[i], minSix);
        minOne = min(one[i], minOne);
    }

    ans = min(minOne * N, min(minSix * (N / 6) + minOne * (N % 6), minSix * (N / 6 + 1)));
    cout << ans << '\n';

    return 0;
}