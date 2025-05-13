// 냅색문제
// https://propercoding.tistory.com/16
// 식의 규칙을 찾아 점화식으로 바꿀것.
#include <iostream>
#include <vector>

using namespace std;

int T(0), N(0), M(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        int ans(0);
        cin >> N;
        vector<int> coin(20);
        for(int i = 0; i < N; i++)
            cin >> coin[i];
        cin >> M;
        int DP[10001] = {0,};
        DP[0] = 1; // 0원일때 경우의수
        for(int i = 0; i < N; i++)
            for(int j = coin[i]; j <= M; j++)
                DP[j] += DP[j - coin[i]];
        
        cout << DP[M] << '\n';
    }

    return 0;
}