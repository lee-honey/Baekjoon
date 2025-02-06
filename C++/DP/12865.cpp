#include <iostream>

using namespace std;

int N(0), K(0);
int DP[101][100001];    // 가치의 최대값
int W[100001], V[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N ; i++)
    {
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= N; i++) // 물건 번호
    {
        for(int j = 0; j <= K; j++) // 버틸수 있는 무게
        {
            if(j >= W[i])
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]] + V[i]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    cout << DP[N][K] << '\n';

    return 0;
}