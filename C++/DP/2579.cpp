#include <iostream>

using namespace std;

int N = 0;
int iScores[301] = {0,};
int dp[301] = {0,};

int Max(int a, int b) { return (a > b) ? a : b; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int n = 0;
        cin >> n;
        iScores[i] = n; 
    }

    dp[1] = iScores[1];
    dp[2] = iScores[1] + iScores[2];
    dp[3] = Max(iScores[2] + iScores[3], iScores[1] + iScores[3]);
    for(int i = 4; i <= N; i++)
        dp[i] = Max(iScores[i] + iScores[i - 1] + dp[i - 3], iScores[i] + dp[i - 2]);

    // 연속된 세 개의 계단을 모두 밟아서는 안된다는 규칙으로 인하여 마지막으로 밟게 될 계단으로부터 케이스를 구하면 
    // 이렇게 규칙이 생성될 수 밖에 없게 된다.

    cout << dp[N] <<'\n';


    return 0;
}