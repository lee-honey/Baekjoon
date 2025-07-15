#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[8]; // 내구도
int W[8]; // 무게
int ans = 0;

void BackTracking(int idx, int cnt)
{
    if (idx == N)
    {
        ans = max(ans, N - cnt); // cnt는 살아남은 계란 수
        return;
    }

    bool bCanHit = false;
    for (int i = 0; i < N; i++)
    {
        if (i != idx && S[i] > 0)
        {
            bCanHit = true;
            break;
        }
    }

    if (!bCanHit || S[idx] <= 0) // 이런 조건일 경우 다른 계란을 치지 않고 그냥 넘어감
    {
        BackTracking(idx + 1, cnt);
        return;
    }

    for (int i = 0; i < N; i++) // 그냥 넘어갈 조건이 아닐 경우 계란을 침
    {
        if (i == idx || S[i] <= 0)
            continue;

        S[idx] -= W[i];
        S[i] -= W[idx];

        int broken = 0;
        if (S[idx] <= 0) broken++;
        if (S[i] <= 0) broken++;

        BackTracking(idx + 1, cnt - broken);

        S[idx] += W[i];
        S[i] += W[idx];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i] >> W[i];

    BackTracking(0, N);

    cout << ans << '\n';
    return 0;
}
