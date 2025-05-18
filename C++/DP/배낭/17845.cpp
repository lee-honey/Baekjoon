#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), K(0);
vector<pair<int, int>> vec;
int DP[10001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int I(0), T(0);
        cin >> I >> T;
        vec.push_back({T, I});
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < K; i++)
    {
        int time = vec[i].first;
        int score = vec[i].second;
        for(int j = N; j >= time; j--)
        {
            DP[j] = max(DP[j], DP[j - time] + score);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}