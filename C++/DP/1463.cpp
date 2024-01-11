#include <iostream>

using namespace std;

/*
1. 1000001 크기짜리 정수형 배열을 만든다.
2. dp[1] = 0을 넣는다.
3. 2부터 N까지 for문을 돌리면서 
    1. 3으로 나누어지는지 보고 X가 1이 되는지 체킹한다. 나누어지면 해당 dp의 값을 1 증가시키고 X 를 / 3 한다.
    2. 2로 나누어지는지 보고 X가 1이 되는지 체킹한다.나누어지면 해당 dp의 값을 1 증가시키고 X 를 / 2 한다.
    3. 3이나 2로 나누어지지 않으면 x에서 -1을 하고 해당 dp의 값을 증가시킨 후 dp[X]을 업데이트한다.
*/

int dp[10000001] = {0,};
int N(0);

int main(void)
{
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    cin >> N;
    for (int i = 2; i <=N; i++)
    {
        int temp[3] = {1000000,1000000,1000000};
        if(i % 3 == 0)
        {
            temp[0] = dp[i / 3] + 1;
        }
        if(i % 2 == 0) //else if문으로 처리하면 안됨.
        {
            temp[1] = dp[i / 2] + 1;
        }
        dp[i] = min(min(temp[0], temp[1]), dp[i - 1] + 1);
    }
    cout << dp[N] << endl;
    return 0;
}