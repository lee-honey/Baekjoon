// 2원과 5원으로만 거슬러줘야함
// 동전의 개수가 최소가 되도록
// 거스름돈이 n인 경우, 최소 동전의 개수가 몇개인지

#include <iostream>

using namespace std;

int n(0);
int DP[100001] = {0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    DP[1] = -1;
    DP[2] = 1;
    DP[3] = -1;
    DP[4] = 2;
    DP[5] = 1;
    DP[6] = 3;
    DP[7] = 2;
    DP[8] = 4;

    for(int i = 9; i <= n; i++)
    {
        if(i % 5 == 0)
            DP[i] = i / 5;
        else
        {
            if(DP[i % 5] == -1)
                DP[i] = DP[i - i % 5 - 5] + DP[i % 5 + 5];
            else
                DP[i] = DP[i - i % 5] + DP[i % 5];
        }
    }

    cout << DP[n] << '\n';

    return 0;
}