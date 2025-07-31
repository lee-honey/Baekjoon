#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), L(0);
vector<int> H;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    H.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    sort(H.begin(), H.end());

    for(int i = 0; i < N; i++)
    {
        if(L < H[i])
            break;
        L++;
    }
    cout << L << '\n';

    return 0;
}