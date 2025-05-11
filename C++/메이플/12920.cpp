// 개수가 여러개이므로 분할해서 푸는 배낭문제
// 기존 평범한 배낭문제와 달리 개수가 정해져있음음
// 2로 나눠가며 분할하지 않으면 log2N가 아닌 N 이 시간복잡도에 곱해져 시간초과.
// 2로 나눠가면 1~M까지의 모든 수를 나타낼 수도 있다.

#include <iostream>
#include <vector>

using namespace std;

int N(0), M(0);
int DP[10001] = {0,};
int V[101] = {0,};
int C[101] = {0,};
int K[101] = {0,};
vector<pair<int, int>> thing;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> V[i] >> C[i] >> K[i]; // 무게 , 만족도, 개수

    for(int i = 0; i < N; i++)
    {
        for(int j = K[i]; j > 0; j >>= 1) // K를 2로 나누면서 0이 될 때까지
        {
            int num = j - (j >> 1);
            thing.push_back({V[i] * num, C[i] * num}); // 각각 무게의 모든 경우의 수와 만족도를 적재
        }
    }

    for(int i = 0; i < thing.size(); i++) // 모든 무게 경우의 수 순회를 돌면서
    {
        int v = thing[i].first;
        int c = thing[i].second;
        for(int j = M; j >= v; j--) // M무게부터 DP를 갱신해나감
            DP[j] = max(DP[j], DP[j - v] + c);
    }

    cout << DP[M] << '\n';

    return 0;
}