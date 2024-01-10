#include <iostream>

using namespace std;
/* 
DP는 이전 값들을 전부 구하면서 누적한다는 것이 중요
*/

int N(0), result(0);
int cost[3] = {0,};
int home[1001][3] = {0,};
int main(void)
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[0];
        home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[1];
        home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[2];
    }

    result = min(min(home[N][0], home[N][1]), home[N][2]);

    cout << result << endl;

    return 0;
}