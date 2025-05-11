#include <iostream>
#include <algorithm>

using namespace std;

int N(0), K(0);
int DP[100001] = {0,};  // 무게 j까지 고려한 최대 가치
int W[101] = {0,};      // 물건 무게
int V[101] = {0,};      // 물건 가치

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];  // 각 물건의 무게와 가치

    for (int i = 1; i <= N; i++)  // 각 물건에 대해
    {
        for (int j = K; j >= W[i]; j--)  // 역순으로 탐색
            DP[j] = max(DP[j], DP[j - W[i]] + V[i]);  // 현재 물건을 넣는 경우와 안 넣는 경우 비교
    }

    cout << DP[K] << '\n';  // 최대 가치 출력
    return 0;
}
