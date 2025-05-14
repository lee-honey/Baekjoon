// 0-1 knapsack문제. 0~N으로 한 요소를 한번씩만 사용하고, 그 안에서는 역순으로for문을 돌리며 구함

#include <iostream>
#include <algorithm>

using namespace std;

int N(0), T(0), ans(0);
int K[101] = {0,};
int S[101] = {0,};
int DP[10001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    for(int i = 0; i < N; i++)
        cin >> K[i] >> S[i];

    for(int i = 0; i < N; i++)
    {
        for(int j = T; j >= K[i]; j--)
        {
            DP[j] = max(DP[j], DP[j - K[i]] + S[i]); // 배낭문제: 현재 물건을 넣을거냐 말거냐중에 큰값으로 DP 설정
            ans = max(ans, DP[j]);
        }
    }

    cout << ans << '\n';

    return 0;
}