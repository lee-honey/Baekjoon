#include <iostream>
int MAX(int a, int b){return (a > b) ? a : b;}
int MIN(int a, int b){return (a < b) ? a : b;}

using namespace std;

int N(0);
int T[16] = {0,};
int P[16] = {0,};
int DP[16] = {0,};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    for(int i = 0; i < N; i++)
    {
        if(i + T[i] <= N)
            DP[i + T[i]] = MAX(DP[i + T[i]], DP[i] + P[i]);
        // 지나간 날짜만큼 뒤에 계산했을 때 값을 갱신할것인지 유지할것인지를 판단
        DP[i + 1] = MAX(DP[i + 1], DP[i]); // 값 누적을 위한 코드
    }

    cout << DP[N] << '\n';

    return 0;
}