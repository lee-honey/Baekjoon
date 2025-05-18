// DP 전처리리 + 그리디 문제

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n = 5;
long long DP[31] = {2, 5, 7, 11, 25}; // 2^i무게의 비용
long long minWeight(26);
long long answer(LLONG_MAX);

void getMinimumCost() {
    long long curCost(0);
    long long curWeight(0);

    for (int i = 0; i < n; ++i) // DP 전처리 (2^i무게의 최소비용)
        DP[i + 1] = min(DP[i + 1], 2 * DP[i]);

    for (int i = n - 1; i >= 0; --i) // 그리디하게 큰 무게부터 채우기(이미 DP로 각 무게들의 최소비용이 세팅되었기 때문에 가장 큰 무게부터 채워나가면 무조건 최소비용이 됨)
    { // 큰 무게부터 채워야 최적의 비용 도출 가능
        long long weight = 1 << i; // 2^i

        if (curWeight + weight <= minWeight) // curWeight가 minWeight가 될때까지 큰 무게부터 채워나감
        {
            long long count = (minWeight - curWeight) / weight;
            curWeight += count * weight;
            curCost += count * DP[i];
        }
        if(curWeight >= minWeight)
            answer = min(answer, curCost);
        else // 부족할 경우 하나 더 채워야 answer의 조건이 됨
            answer = min(answer, curCost + DP[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getMinimumCost();
    cout << answer << '\n';

    return 0;
}
